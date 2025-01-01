#include<bits/stdc++.h>
using namespace std;
int num[4];
int a[100];
int sum=0, ans=0, l,r;
void dfs(int x, int n){
	if(x>=n){//边界，自顶向下 
		ans = min(ans, max(l,r));
//		cout<<"l:"<<l<<" r:"<<r<<endl;
		return;
	}
	l+=a[x];
	dfs(x+1, n);
	l-=a[x];
	r+= a[x];
	dfs(x+1, n);
	r-= a[x];
} 
void solve(int n){
	for(int i=0;i<n;i++){
		cin>>a[i];//2 4 3
	}
	l=0, r=0, ans = int(2e9);
	dfs(0, n);
	sum+=ans; 
	
}
int main(){
	for(int i=0;i<4;i++){
		cin>>num[i];
	}
	for(int i=0;i<4;i++){
		solve(num[i]);
	}
	cout<<sum;
}
/*
2 2 1 3		
5 6
4 3
6
2 4 3
*/
