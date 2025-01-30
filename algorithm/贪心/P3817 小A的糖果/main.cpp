#include<iostream>
#include<cstdio>
using namespace std;
const int maxN = 1e5+5;
int a[maxN],n,x;
typedef long long ll;
ll sum = 0;
int main(){//负数？ 
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){//对第一个糖果特殊处理 
		if(a[i]+a[i-1]>x){
			sum+=a[i]+a[i-1]-x;
			a[i] -= a[i]+a[i-1]-x;
		}
	}
	cout<<sum<<endl;
	
}
/*
3 3
2 2 2

3 11
999 0 12
*/
