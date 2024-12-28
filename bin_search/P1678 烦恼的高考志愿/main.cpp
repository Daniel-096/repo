#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e5+5;
int s[maxN], a[maxN];
int main(){
	int n, m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	ll sum = 0;
	sort(s, s+n);
	for(int i=0;i<m;i++){
		int l = 0, r = n-1, mid, tar;
		while(l<r-1){
			mid = l+(r-l)/2;
			tar = s[mid]-a[i];
			if(tar>0){//学校过大 
				r=mid;
			}
			else if(tar<0){
				l = mid;
			}
			else{//一样 
				break;
			}
		}
		if(tar!=0){//没找到一样
			if(s[l]-a[i]>0){
				sum+= s[l]-a[i];
			} 
			else if(a[i]-s[r]>0){
				sum+=a[i] -s[r];
			}
			else{
				sum+=a[i]-s[l]<s[r]-a[i]?a[i]-s[l]:s[r]-a[i];
			}
		}
	}
	cout<<sum<<endl;
	
} 
/*
4 3
513 598 567 689
500 600 550
*/
