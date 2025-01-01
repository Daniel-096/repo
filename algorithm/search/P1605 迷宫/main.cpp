#include<bits/stdc++.h>
using namespace std;
const int maxN = 10;
int g[maxN][maxN];//����1 ���ϰ� -1 
int n,m,t,bx,by,ex,ey,ans=0;
int step[4][2]={{0,1},{1,0},{-1,0},{0,-1}};//�±��1��ʼ 
void dfs(int x, int y){
//	cout<<"x:"<<x<<" y:"<<y<<endl;
	if(x==ex&&y==ey){
		ans++;
		return;//�߽� 
	}
	for(int i=0;i<4;i++){
		int x1 = x+step[i][0];
		int y1 = y+step[i][1];
		if(x1>0&&x1<=n&&y1>0&&y1<=m && g[x1][y1]==0){
			g[x1][y1] = 1;
			dfs(x1, y1);
			g[x1][y1] = 0;//���� 
		}
	}
}
int main(){
	cin>>n>>m>>t>>bx>>by>>ex>>ey;
	memset(g, 0, sizeof(g)); 
	for(int i=0;i<t;i++){
		int x,y;
		cin>>x>>y;
		g[x][y] = -1;
	}
	if(g[bx][by]==0)g[bx][by]= 1;//���
	else{ //������㱻���� 
		cout<<0;return 0; 
	} 
	dfs(bx,by);
	cout<<ans<<endl; 
} 
/*
2 2 1
1 1 2 2
1 2

3 2 1
1 1 2 2
1 2

3 2 1
1 1 2 2
1 1
*/
