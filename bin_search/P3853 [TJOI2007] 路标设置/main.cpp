#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5+5;
int a[maxN];
int main(){
	int L,n,m;
	cin>>L>>n>>m;
	for(int i =0;i<n;i++)
		cin>>a[i];
	int l=1,r = L;
	
	while(l<r){//第一个
		int mid = l+(r-l)/2;
		int cur = 0,cnt=0, pos=0;//检验mid (貌似默认首位是有路标的）
//		cout<<"l:"<<l<<" r:"<<r<<" mid:"<<mid<<endl; 
		while(cur<n-1){
			if(pos==0){
				pos = a[cur];//没有距离时，给距离赋值 
			}
			if(a[cur+1]-pos>mid){//中间值 
				cnt++;//放标 
				pos += mid;//新位置 
			}
			else {
				pos=0;
				cur++;
			}
		}
		if(cnt>m){
			l = mid+1;
		}
		else{
			r = mid;
		}
	}
	cout<<l<<endl;
} 
/*
101 2 1
0 101
*/
