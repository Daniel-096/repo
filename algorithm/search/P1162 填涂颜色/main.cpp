#include<bits/stdc++.h>
using namespace std;
int n, g[100][100];//逆天有死循环bug 
bool flag;//回溯 bug:不标记vis，回溯后会有死循环（重复访问边界零） 
int step[4][2] = {{1,0},{0,1},{-1, 0}, {0,-1}};
void dfs(int x, int y){ //自底向上 
//	cout<<"x:"<<x<<" y:"<<y<<endl;
	for(int i=0;i<4;i++){
		int x1 = x+step[i][0];
		int y1 = y+step[i][1];
		if(g[x1][y1]==-1){//越界 
			flag = false;
			return;
		}
		if(g[x1][y1]==0){
			g[x1][y1] =2;
			dfs(x1, y1);
			if(!flag)g[x1][y1]=3;//边界0标记为3 (省去vis矩阵 
		}//遇到1不需要处理 
	}
}
int main(){
	cin>>n;
	memset(g, -1, sizeof(g));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){//少一个越界判断 ？ 
			cin>>g[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(g[i][j]==0){
				flag =true;//要删 
				g[i][j]=2;
				dfs(i,j);
				if(!flag)g[i][j]=3;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(g[i][j]==3)cout<<0;
			else cout<<g[i][j];
			if(j<n)cout<<' ';
		}
		cout<<endl;
	} 
} 
/*
3
0 1 1
1 0 1
1 1 1

4
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0

4
0 1 1 1
1 0 0 1
1 1 0 1
1 1 1 0

4
0 1 1 1
1 0 0 1
1 1 0 0
1 1 1 0

1
0

4
1 1 1 1
1 0 0 1
1 0 0 1
1 1 1 1
*/
