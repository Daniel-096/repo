#include<bits/stdc++.h>
using namespace std;
const int maxN = 505;
int n,m,k, g[maxN][maxN], step[4][2]={{1,0},{-1,0},{0,1},{0,-1}}, maxH, minStep;
bool vis[maxN][maxN];
struct Node{
	int x;
	int y;
};
void bfs(int x,int y){
	queue<Node>q;
	Node tmp;
	tmp.x=x;
	tmp.y=y;
	vis[x][y]=true;
	maxH = g[x][y];
	minStep = 0;
	q.push(tmp);
	int level = 1;
	while(!q.empty()){
		int len = q.size();
		while(len--){
			Node cur = q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int dx = cur.x+step[i][0];
				int dy = cur.y+step[i][1];
				if(!vis[dx][dy]&& g[dx][dy]!=-1 &&abs(g[dx][dy]-g[cur.x][cur.y])<=k){//没访问，不越界，高度差在范围内 
					vis[dx][dy]=true;
					tmp.x=dx;
					tmp.y=dy;
					q.push(tmp);
					if(g[dx][dy]==maxH&&level<minStep){
						minStep=level;
					}
					else if(g[dx][dy]>maxH){
						minStep=level;
						maxH = g[dx][dy];
					}
				}
			}
		}
		level++;
	}
}
int main(){
	cin>>n>>m>>k;
	memset(g,-1,sizeof(g));
	memset(vis, false, sizeof(vis));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
		}
	}

	bfs(1,1);//输入起点 
	cout<<maxH<<" "<<minStep<<endl;
}
/*
5 4 1
0 1 2 0
1 0 0 0
1 0 1 2
1 3 1 0
0 0 0 9

*/
 
