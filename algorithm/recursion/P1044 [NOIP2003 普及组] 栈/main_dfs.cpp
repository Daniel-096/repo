#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
const int maxN = 20;
ll dp[maxN][maxN];// c n m
ll dfs(int x, int y){
	if(dp[x][y]>0)return dp[x][y];
	if(x==0)return 1;//x为空，全部出栈 
	if(y>0)dp[x][y]+=dfs(x,y-1);//栈内有元素，出栈 
	dp[x][y]+=dfs(x-1,y+1);//x元素入栈 
	return dp[x][y];
}
int main(){
	cin>>n;
	memset(dp, 0, sizeof(dp));
	cout<<dfs(n,0)<<endl;
}
/*

*/
