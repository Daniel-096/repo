#include<bits/stdc++.h>
using namespace std;
int a[100], b[100], c[100], d[100], n, cnt=0;
void print(){
	for(int i=1;i<=n;i++){
		cout<<a[i];
		if(i<n)cout<<' ';
	}
	cout<<endl;
}
void dfs(int i){
	//1边界（自顶向下
	if(i>n){
		cnt++;
		if(cnt<=3){
			print();
		}
	} 
	for(int j=1;j<=n;j++){
		if(!a[i] && !b[j] && !c[i+j] && !d[i+n-j]){
			a[i]=j;
			b[j]=1;
			c[i+j]=1;
			d[i+n-j]=1;
			dfs(i+1);
			a[i]=0;
			b[j]=0;
			c[i+j]=0;
			d[i+n-j]=0;
		}
	}
}
int main(){
	cin>>n;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	memset(d, 0, sizeof(d));
	dfs(1);
	cout<<cnt<<endl;
}
