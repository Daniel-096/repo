#include<bits/stdc++.h>
using namespace std;
const int maxN = 205;
int n,m,k,cnt=0,step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char a[maxN][maxN];
bool vis[maxN][maxN];
void dfs(int x, int y){
	for(int i=0;i<4;i++){
		int dx = x+step[i][0];
		int dy = y+step[i][1];
		if(!vis[dx][dy]&&a[dx][dy]!='#'){
			vis[dx][dy]=true;
			if(a[dx][dy]=='E'){
				cnt++;
			}
			dfs(dx,dy);
		}
	}
}
int main(){
	memset(vis, false, sizeof(vis));
	memset(a, '#', sizeof(a));
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	int cntG = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
			if(!vis[i][j]&&a[i][j]!='#'){
				cnt=0;
				vis[i][j]=true;
				if(a[i][j]=='E'){
					cnt++;
				}
				dfs(i,j);
				if(cnt<k){
					cntG++;
				}
			}

		}	
	}
	cout<<cntG<<endl;
	
}
/*
3 5 2
..#EE
E.#E.
###..

3 5 2
..#..
.E#E.
###..

*/
