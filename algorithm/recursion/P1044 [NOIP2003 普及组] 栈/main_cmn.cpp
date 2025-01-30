#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
const int maxN = 20;
ll c[maxN*2][maxN];// c n m
int main(){
	cin>>n;
	ll ans =1;
	for(int i=1;i<=n*2;i++){// c 2n n
		c[i][0] = 1;
		c[i][i] = 1;
		for(int j=1;j<i;j++){
			c[i][j] = c[i-1][j]+c[i-1][j-1];
		}
	}
	cout<<c[2*n][n]/(n+1)<<endl;
}
/*
3

*/
