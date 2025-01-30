#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[305],n;
int main(){
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=0,r=n;
	ll ans = 0;
	while(l<r){
//		cout<<"l:"<<l<<" r:"<<r<<endl;
		
		ans += (a[r]-a[l])*(a[r]-a[l]);
//		cout<<ans<<endl; 
		l++;
//		cout<<"l:"<<l<<" r:"<<r<<endl;
		if(l<r){
			ans += (a[r]-a[l])*(a[r]-a[l]);
//			cout<<ans<<endl; 
			r--;
		}
		
	}
	cout<<ans<<endl;
	
	
	
}
