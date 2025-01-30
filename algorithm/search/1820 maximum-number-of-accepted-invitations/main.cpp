#include<bits/stdc++.h>
using namespace std;
const int maxN = 505;
//match存每个j对应的i，初值为-1；vis表示每个i访问过的j，初值为false
int n,m,a[maxN][maxN], match[maxN], vis[maxN], ans=0; 
bool dfs(int index, int *vis){
	for(int j=0;j<m;j++){
		if(!vis[j]&&a[index][j]){//没访问且有连线 
			vis[j]=true;
			if(match[j]==-1||dfs(match[j], vis)){
				match[j]=index;
				return true;
			}
		}
	}
	return false;//base case
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	//dfs
	
	memset(match, -1, sizeof(match));
	for(int i=0;i<n;i++){//遍历每个左节点 ,看看能不能连上 
		memset(vis,false, sizeof(vis));
		if(dfs(i, vis)){
			ans++;
		}
	}
	cout<<ans<<endl;
//	for(int i=0;i<m;i++){
//		cout<<"j:"<<i<<" to i:"<<match[i]<<endl;
//	}
}
/*
4 4
1 0 1 0
1 0 0 0
0 0 1 0
1 1 1 0

3

3 4
1 0 1 0
1 0 0 0
0 0 1 0

2

3 2
1 0
1 0
0 1

2
*/
