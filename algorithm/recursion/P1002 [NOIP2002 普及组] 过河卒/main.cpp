#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll dp[25][25];
bool vis[25][25];
int n, m, hx,hy, step[9][2]={{2,1},{1,2},{-1,2},{-2,1},
						{-2,-1},{-1,-2},{1,-2},{2,-1},{0,0}};//含原位 

int main(){
	cin>>n>>m>>hx>>hy;
	n++;m++;
	memset(dp, 0, sizeof(dp));
	memset(vis, false, sizeof(vis));
	for(int i=0;i<9;i++){
		int x1 = step[i][0]+hx;
		int y1 = step[i][1]+hy;
		if(x1>=0&&x1<n && y1>=0&&y1<m){//不越界 
			vis[x1][y1] = true;
		}
	}
	bool flag = true;
	for(int i=0;i<m;i++){//边界值 
		if(vis[0][i]&&flag)flag = false;
		if(flag)dp[0][i] = 1;
	}
	flag = true;
	for(int i=0;i<n;i++){
		if(vis[i][0]&&flag)flag = false;
		if(flag)dp[i][0] = 1;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(!vis[i][j])dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	cout<<dp[n-1][m-1]<<endl;
}
/*
3 4 2 3

6 6 3 3

20 20 6 6
*/
