#include<bits/stdc++.h>
using namespace std;
int n;
char a[105][105];
bool  flag;//����Ƿ���� 
int  vis[105][105];
int step[8][2] = {{0,1}, {1,1}, {1,0},{1,-1},
					{0,-1},{-1,-1},{-1,0},{-1,1}};
char tar[10] = "yizhong";
void dfs(int x, int y, int cur,int dir){//���㶨����//�ӵ����� �� 
	if(cur==7){//�߽� 
		flag = false;//����ȥ 
		return;
	}
	int x1 = x+step[dir][0];
	int y1 = y+step[dir][1];
	if(x1>=0&&x1<n&&y1>=0&&y1<n&&a[x1][y1]==tar[cur]){
		vis[x1][y1]++;
		dfs(x1,y1,cur+1, dir);
		if(flag)vis[x1][y1]--;
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	memset(vis, 0, sizeof(vis));//Ϊ0��û���ʣ�����0Ϊ��η��� 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==tar[0]){
				for(int k=0;k<8;k++){
					flag = true;
					vis[i][j]++;
					dfs(i,j,1,k);
					if(flag)vis[i][j]--;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(vis[i][j]==0)cout<<"*";
			else cout<<a[i][j];
		}
		cout<<endl;
	}
	
} 
/*
8
qyizhong
gydthkjy
nwidghji
orbzsfgz
hhgrhwth
zzzzzozo
iwdfrgng
yyyygggg

8
qyizhong
gidthkjy
nzidghji
ohbzsfgz
hogrhwth
znzzzozo
igdfrgng
yyyygggg
*/
