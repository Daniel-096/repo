#include<bits/stdc++.h>
using namespace std;
int num[4];
int a[100];
int ans=0;

void solve(int n){
	int sum = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];//2 4 3
		sum+= a[i];
	}//01背包
	int dp[65][1205], bagSize = sum/2;
	memset(dp, 0, sizeof(dp));
	for(int j=a[0];j<=bagSize;j++){//边界 
		dp[0][j]=a[0];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=bagSize;j++){
			if(j<a[i])dp[i][j]=dp[i-1][j];//一定装不下
			else dp[i][j]=max(dp[i-1][j], dp[i-1][j-a[i]]+a[i]); //价值等于重量 
		}
	}
	ans+=max(sum-dp[n-1][bagSize], dp[n-1][bagSize]);

	
}
int main(){
	for(int i=0;i<4;i++){
		cin>>num[i];
	}
	for(int i=0;i<4;i++){
		solve(num[i]);
	}
	cout<<ans;
}
/*
2 2 1 3		
5 6
4 3
6
2 4 3
*/
