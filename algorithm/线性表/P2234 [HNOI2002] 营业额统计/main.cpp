#include<bits/stdc++.h>
using namespace std;
int n;
const int maxN = 1e8+5;
set<int>s;

int main(){//stl
	cin>>n;
	s.insert(maxN);
	s.insert(-maxN);
	int sum=0;
	for(int i=0;i<n;i++){
		int cur=0;
		scanf("%d",&cur);
		if(i==0){
			sum+=cur;
			s.insert(cur);
		}
		else{
			auto p = s.lower_bound(cur);
			if(*p==cur){
				continue;
			}
			else{
				auto pos = p;
				p--;
				sum+=min(*pos-cur,cur-*p);
				s.insert(cur);
			}
		}
	}
	cout<<sum<<endl;
	
}
/*
6
5
1
2
5
4
6

4
-3
-2
-4
-5
*/
