#include<bits/stdc++.h>
using namespace std;
const int maxN = 505;
//match存每个j对应的i，初值为-1；vis表示每个i访问过的j，初值为false
int n,m,k,a[maxN][maxN], match[maxN], vis[maxN]; 
bool dfs(int index, int *vis,int cur){
	for(int j=0;j<m;j++){
		if(!vis[j]&&a[index][j]>0&&a[index][j]<=cur){//没访问且有连线 
			vis[j]=true;
			if(match[j]==-1||dfs(match[j], vis, cur)){
				match[j]=index;
				return true;
			}
		}
	}
	return false;//base case
}
bool check(int cur){
	//dfs
	int ans=0;
	memset(match, -1, sizeof(match));
	for(int i=0;i<n;i++){//遍历每个左节点 ,看看能不能连上 
		memset(vis,false, sizeof(vis));
		if(dfs(i, vis, cur)){
			ans++;
		}
	}
//	cout<<"cur:"<<cur<<" cnt:"<<ans<<endl;
	return ans>=n-k+1;
}
int main(){
	cin>>n>>m>>k;
	int l=1e9, r=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			l = min(l,a[i][j]);
			r = max(r,a[i][j]);
		}
	}
	while(l<r){//000111
		int mid = l+(r-l)/2;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid+1;
		}
	}
	cout<<l<<endl;
//	for(int i=0;i<m;i++){
//		cout<<"j:"<<i<<" to i:"<<match[i]<<endl;
//	}
}
/*
3 4 2
1 5 6 6
8 3 4 3
6 8 6 3




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
