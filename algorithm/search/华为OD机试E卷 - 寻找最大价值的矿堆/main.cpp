#include<bits/stdc++.h>
using namespace std;
const int maxN = 205;
int n,m,k,cnt=0,step[4][2]={{1,0},{-1,0},{0,1},{0,-1}},a[maxN][maxN];
//char ;
bool vis[maxN][maxN];
void dfs(int x, int y){
	for(int i=0;i<4;i++){
		int dx = x+step[i][0];
		int dy = y+step[i][1];
		if(!vis[dx][dy]&&a[dx][dy]!=0){
			vis[dx][dy]=true;
			cnt+=a[dx][dy];
			dfs(dx,dy);
		}
	}
}
int main(){
	memset(vis, false, sizeof(vis));
	memset(a, 0, sizeof(a));
//	cin>>n;
	int i=1;
	string s;
//	for(int i=1;i<=n;i++){
	while(cin>>s){
//		cin>>s;
		m = s.size();
		for(int j=1;j<=m;j++){
			a[i][j] = s[j-1]-'0';
		}
		i++;
	}
	n=i-1;
	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
			if(!vis[i][j]&&a[i][j]!=0){
				vis[i][j]=true;
				cnt =0;
				cnt+=a[i][j];
				dfs(i,j);
				ans = max(ans, cnt);
			}

		}	
	}
	cout<<ans<<endl;
	
}
/*
10
2000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000
0000000000


4
22220
00000
00000
01111

4
22220
00020
00010
01111


//每给行数 
*/
