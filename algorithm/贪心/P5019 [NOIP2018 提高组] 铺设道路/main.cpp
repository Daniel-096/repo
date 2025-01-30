#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
int n,a[(int)1e5+5];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ll cnt = a[0];
	for(int i=1;i<n;i++){
		if(a[i]-a[i-1]>0){
			cnt+=a[i]-a[i-1];
		}
	}
	cout<<cnt<<endl;
}
/*
6   
4 3 2 5 3 5 

4
2 2 2 2
4
2 4 2 2
*/
