#include<bits/stdc++.h>
using namespace std;
int n,k, sum=0,cnt=0, ans=0;
int a[100];

bool check(int sum){//ÅĞ¶ÏËØÊı 
	int m = int(sqrt(sum));
	for(int i=2;i<=m;i++){
		if(sum%i==0)return false;
	}
	return true;
}
void dfs(int x){
	
	if(cnt>k){//¹ı¶à 
		return;
	}
	if(x==n){ 
		if(cnt==k&&check(sum)){
//			cout<<"x:"<<x<<" sum:"<<sum<<" cnt:"<<cnt<<endl;
			ans++;
		}
		return;
	}
	sum+=a[x];
	cnt++;
	dfs(x+1);
	sum-=a[x];
	cnt--;
	dfs(x+1);
	
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<ans<<endl;
}
/*
4 3
3 7 12 19
*/
