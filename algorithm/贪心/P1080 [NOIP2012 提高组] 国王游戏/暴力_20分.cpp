#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans = 2e9;//min
const int maxN = 1e3+5;
int n,a[maxN][2];
bool vis[maxN];
void dfs(ll pre,int i,int cnt, ll maxTmp){
	maxTmp = max(maxTmp, pre/a[i][1]);//局部最大 
	if(maxTmp>=ans){
		return;
	}
	if(cnt>=n){//第n个 
		ans = min(maxTmp,ans);//更新全局最优 
		return;
	}
	pre*=a[i][0];
	for(int j=1;j<=n;j++){
		if(!vis[j]){
			vis[j]=true;
			dfs(pre, j, cnt+1, maxTmp);
			vis[j]=false;
		}
	}
}
int main(){
	memset(vis, false, sizeof(vis));
	cin>>n;
	for(int i=0;i<=n;i++){
		scanf("%d %d", &a[i][0], &a[i][1]);
	}
	for(int i=1;i<=n;i++){//选开头 
		vis[i]=true;
		dfs(a[0][0],i,1,0); 
		vis[i]=false;
	}
	cout<<ans<<endl;
}
/*
3 
1 1 
2 3 
7 4 
4 6 

3 
1 1 
4 6 
7 4 
2 3 


*/