#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1005];//记忆化搜索 
int n;
int dfs(int x){//自底向上 
	if(x==0||x==1)return 1;
	for(int j = 0;j<=x/2;j++){
		if(dp[j]==0){
			dp[x]+=dfs(j);
		}
		else dp[x]+=dp[j];

	}
	return dp[x];
}
int main(){
	memset(dp, 0, sizeof(dp));
	dp[0]=1, dp[1]=1;
	cin>>n;
//	dfs(n);
//	cout<<dp[n]<<endl;
	cout<<dfs(n)<<endl;
//	for(int i=0;i<=n;i++){
//		cout<<"i:"<<i<<" dp:"<<dp[i]<<endl;
//	}
	
}
/*
3
1+1+1
1+2
*/
