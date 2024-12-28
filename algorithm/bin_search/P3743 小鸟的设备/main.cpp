#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5+5;
int a[maxN], b[maxN];

int main(){
	int n, m;
	cin>>n>>m;
	double sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	if(sum<=m){
		cout<<-1<<endl;
		return 0;
	}
	//льеп-1 
	double l=0, r = 1e11;
	while(l<r-0.00001){
		double mid = l+(r-l)/2;//╪Л╡И
		sum = 0;
		for(int i=0;i<n;i++){
			double tmp = a[i]*mid - b[i];
			if(tmp>0){
				sum+=tmp;
			}
		}
		if(mid*m<sum){
			r = mid-0.00001;
		}
		else{
			l=mid;
		}
	}
	cout<<l<<endl;
}
/*
3 5
4 3
5 2
6 1

3 100
4 3
5 2
6 1
*/
