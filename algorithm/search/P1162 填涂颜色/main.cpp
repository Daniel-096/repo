#include<bits/stdc++.h>
using namespace std;
int n, g[100][100];//��������ѭ��bug 
bool flag;//���� bug:�����vis�����ݺ������ѭ�����ظ����ʱ߽��㣩 
int step[4][2] = {{1,0},{0,1},{-1, 0}, {0,-1}};
void dfs(int x, int y){ //�Ե����� 
//	cout<<"x:"<<x<<" y:"<<y<<endl;
	for(int i=0;i<4;i++){
		int x1 = x+step[i][0];
		int y1 = y+step[i][1];
		if(g[x1][y1]==-1){//Խ�� 
			flag = false;
			return;
		}
		if(g[x1][y1]==0){
			g[x1][y1] =2;
			dfs(x1, y1);
			if(!flag)g[x1][y1]=3;//�߽�0���Ϊ3 (ʡȥvis���� 
		}//����1����Ҫ���� 
	}
}
int main(){
	cin>>n;
	memset(g, -1, sizeof(g));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){//��һ��Խ���ж� �� 
			cin>>g[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(g[i][j]==0){
				flag =true;//Ҫɾ 
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
