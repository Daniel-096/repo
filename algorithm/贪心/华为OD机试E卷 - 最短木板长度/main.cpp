#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxN = 1e3+5;
int a[maxN], n,m; 
bool check(int tar,int sum){
	for(int i=0;i<n;i++){
		if(a[i]<tar){
			if(sum-(tar-a[i])>=0){
				sum -= tar-a[i];
			}
			else return false;
		}
	}
	return true;
}
int main(){
	cin>>n>>m;
	int l = 1e9, r = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		r = max(r,a[i]+m/n);
		l = min(l, a[i]);
	}
	while(l<r){
		int mid = l+(r-l+1)/2;
		if(check(mid,m)){
			l = mid;
		}
		else{
			r = mid-1;
		}
	}
	cout<<l<<endl;
}
/*
5 3
4 5 3 5 5

*/
