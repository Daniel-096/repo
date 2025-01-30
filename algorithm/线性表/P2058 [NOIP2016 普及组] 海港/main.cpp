#include<bits/stdc++.h>
using namespace std;
int n;
const int maxN = 1e5+5, maxLen = 86400;
unordered_set<int>s;
int a[maxN];
struct Node{
	int id;
	int t;
};
queue<Node>q;
int main(){
	cin>>n;
	memset(a, 0, sizeof(a));
	while(n--){
		int t,m;
		cin>>t>>m;
		
		//1 去掉过时的点 
		while(!q.empty()){
			Node tmp = q.front();
			if(t - tmp.t>=maxLen){
				int cur = tmp.id;
				q.pop();
				a[cur]--;
				if(a[cur]==0){
					auto p = s.find(cur);
					s.erase(p);
				}
			}
			else{
				break;
			}
		}
		for(int i=0;i<m;i++){//2 加入新点 
			Node b;
			cin>>b.id;
			b.t = t;
			q.push(b);
			if(a[b.id]==0){
				s.insert(b.id);
			}
			a[b.id]++;
		}
		cout<<s.size()<<endl;
	}
}
/*
2
1 4 1 2 2 3
86401 3 2 3 4

4
1 4 1 2 2 3
3 2 2 3
86401 2 3 4
86402 1 5
*/
