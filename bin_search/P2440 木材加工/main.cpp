#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+5;
int a[maxN];
int main(){
	int n,k;
	cin>>n>>k;
	int l=0, r =0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		r =max(r, a[i]);
	}
	while(l<r){
		int mid = l+(r-l+1)/2;
		int cnt = 0;
		for(int i=0;i<n;i++){
			cnt+=a[i]/mid;
		}
		if(cnt>=k){
			l =mid;
		}
		else{
			r = mid-1;
		}
	}
	cout<<l<<endl;
	
}
/*
3 7
232
124
456
*/
