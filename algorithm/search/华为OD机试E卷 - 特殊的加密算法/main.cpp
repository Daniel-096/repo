#include<bits/stdc++.h>
using namespace std;
const int maxN = 505;
int n,m,a[maxN][maxN], step[4][2]={{1,0},{-1,0},{0,1},{0,-1}},text[maxN];
string ans ="";
bool vis[maxN][maxN];
void dfs(int x, int y, int index, string &s){//top down
	if(index>=n){//1 base case
		if(ans==""||ans>s){
			ans = s;
		}
		return;
	}
	for(int i=0;i<4;i++){
		int dx = x+step[i][0];
		int dy = y+step[i][1];
		if(a[dx][dy]==text[index]&&!vis[dx][dy]){//没越界、符合下一个；没访问 
			vis[dx][dy]=true;
			s=s+to_string(dx-1)+to_string(dy-1);
			dfs(dx,dy, index+1, s);
			s = s.substr(0,s.size()-2);//回溯 
			vis[dx][dy]=false;
		}
	}
}

int main(){
	cin>>n;
	memset(a,-1,sizeof(a));
	memset(vis, false, sizeof(vis));
	for(int i=0;i<n;i++){
		cin>>text[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){//下标为1 
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==text[0]){
				string s =to_string(i-1)+to_string(j-1);
				vis[i][j]=true;
				dfs(i,j,1,s); 
				vis[i][j]=false;//回溯 
			}
		}
	}
	if(ans!=""){
		for(int i=0;i<ans.size();i++){
			cout<<ans[i];
			if(i<ans.size()-1)cout<<" ";
		}cout<<endl;
	}
	else cout<<"error"<<endl;
	
} 
/*
2
0 3
3
0 0 2
1 3 4
6 6 4

2
0 2
3
0 0 2
1 2 4
6 6 4

2
0 2
3
0 0 2
1 0 4
6 6 4

*/
