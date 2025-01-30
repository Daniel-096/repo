#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5+5;
int m,n,a[maxN], b[maxN];
int main(){
	cin>>m;
	while(m--){
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		int i=0,j=0;
		stack<int>st;
//		scanf("%d",&cur);
		bool flag = true;
		while(j<n){
			if(b[j]==a[i]){
//				scanf("%d",&cur);
				j++;
				i++;
			}
			else if(!st.empty()&&st.top()==b[j]){
//				scanf("%d",&cur);
				st.pop();
				j++;
			}
			else if(i<n){
				st.push(a[i]);
				i++;
			}
			else{
				flag = false;
				break;
			}
		}
		if(flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
/*
2
5
1 2 3 4 5
5 4 3 2 1
4
1 2 3 4
2 4 1 3

2
4
1 2 3 4
2 4 1 3
5
1 2 3 4 5
5 4 3 2 1

2
4
1 2 3 4
2 4 1 3

*/
