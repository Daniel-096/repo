#include<bits/stdc++.h>
using namespace std;
int m,n,a[108],cnt=0,b[108],cur=0; 
void dfs(int x,int i){
	if(x==0){
		cnt++;
		return;
	}
	if(i==n){
		return;//取完所有菜，人不服 
	}
	if(x-a[i]>=0){
		dfs(x-a[i],i+1);
	}
	dfs(x,i+1);
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(m, 0);
	cout<<cnt<<endl;
}
/*
4 4
1 2 1 2

4 4
0 0 2 2
//菜价格大于0 
*/
