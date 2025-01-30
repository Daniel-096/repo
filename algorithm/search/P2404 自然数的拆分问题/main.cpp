#include<bits/stdc++.h>
using namespace std;
int a[100];
int n;
void dfs(int x, int len){//自底向上 
	for(int j = a[len-1];j<=x;j++){ //当j==x时，相当于不做分割 
		if(j<n){//不超过最大值n (避免当x==n时，j取到n，不符题意） 
			a[len]=j;
			x-=j;
			if(x==0){
				for(int i=1;i<=len;i++){
					cout<<a[i];
					if(i<len)cout<<"+";
				}
				cout<<endl;
			}
			else dfs(x, len+1);
			x+=j;
		}
	}
}
int main(){
	cin>>n;
	a[0] = 1;//初值 
	dfs(n, 1);
}
/*
3
1+1+1
1+2
*/
