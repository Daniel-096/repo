#include<bits/stdc++.h>
using namespace std;
int step[8][2] = {{1,2},{2,1}, {-1, -2}, {-2,-1}, {-1, 2}, {-2,1}, {1, -2}, {2,-1}};
int ans[500][500];
//bool vis[500][500];
int n, m;
struct Node{
	int x;
	int y;
};
int main(){
	queue<Node> q;
	int x,y,w=1,cnt=0;
	Node tmp;
	cin>>n>>m>>tmp.x>>tmp.y;
	q.push(tmp);
	memset(ans, -1, sizeof(ans));//��ֵ 
	ans[tmp.x][tmp.y]=0;
	
	while(!q.empty()){//��� (����һ����ֵ����һ����ֵ��ʡȥ������ 
		Node cur = q.front();
		q.pop();
		for(int i=0;i<8;i++){
			int x1 = cur.x+step[i][0];
			int y1 = cur.y+step[i][1];
			if(x1>0&&x1<=n&&y1>0&&y1<=m&& ans[x1][y1]<0){//û�����Ҳ�Խ�� ����1,1��ʼ 
				ans[x1][y1]=ans[cur.x][cur.y]+1;
				tmp.x = x1;
				tmp.y = y1;
				q.push(tmp);
			}
		}
		
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j];
			if(j<m)cout<<"\t";
			else cout<<endl;
		}
	}
	
	
}
/*
3 3 1 1
4 4 1 2
*/
