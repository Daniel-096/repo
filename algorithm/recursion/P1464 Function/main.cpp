#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;
ll dp[25][25][25];
ll dfs(ll a, ll b, ll c){
	if(a<=0||b<=0||c<=0)return 1;
	if(a>20||b>20||c>20){
		return dfs(20,20,20);
	}
	if(dp[a][b][c]>0)return dp[a][b][c];//º«“‰ 
	if(a<b&&b<c){
		dp[a][b][c] = dfs(a,b,c-1)+dfs(a,b-1,c-1)-dfs(a,b-1,c);
		
	}
	else{
		dp[a][b][c] = dfs(a-1,b,c) + dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1);
	}
	return dp[a][b][c];
}
int main(){
	memset(dp,0, sizeof(dp));
	while(cin>>a>>b>>c){
		if(a==-1&&b==-1&&c==-1){
			return 0;
		}
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<dfs(a,b,c)<<endl;
	}
} 

/*
1 1 1
2 2 2
-1 -1 -1
*/
