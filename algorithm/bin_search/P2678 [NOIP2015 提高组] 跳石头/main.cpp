#include<bits/stdc++.h>
using namespace std;
const int maxN = 5e4+5;

int a[maxN];
int main(){
	int dist, n ,k;
	cin>>dist>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	a[n] = dist; 
	int l=1, r = dist;//第一个 
	while(l<r){//准确值。。 
		int mid = l+(r-l+1)/2;
		int cnt = 0, tmp = 0; 
		for(int i=0;i<n+1;i++){
			tmp+= i>0?a[i]-a[i-1]:a[i];
			if(tmp<mid){//中间 过短 
				cnt++; 
			}
			else{
				tmp = 0;//长度够长 
			}
		}
//		cout<<"l:"<<l<<" r:"<<r<<" cnt:"<<cnt<<" mid:"<<mid<<endl; 
		if(cnt>k){
			r = mid-1;
		}
		else{
			l=mid;
		}
	}
	cout<<r<<endl;
}
/*
25 5 2 
2
11
14
17 
21
*/
