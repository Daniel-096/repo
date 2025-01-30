#include<bits/stdc++.h>
using namespace std;
int dp[108][10008];
int main(){
	int n,m,a[108];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		dp[i][0]=0;//³õÖµ 
	}
	dp[0][a[0]]=1;
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]>j){
				dp[i][j] = dp[i-1][j];
			}
			else if(a[i]<j){
				dp[i][j] = dp[i-1][j-a[i]]+dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j]+1;
			}
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<=m;j++){
//			cout<<dp[i][j]<<' ';
//		}cout<<endl;
//	}
	cout<<dp[n-1][m]<<endl;
}
/*
4 4
1 1 2 2
*/
