#include<bits/stdc++.h>
using namespace std;
int a[10000][10000],n,m;//��Ʒ������ 
int num[10000],sum=0;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0;i<n;i++){//��Ʒ
		for(int j=1;j<m;j++){
			if (a[i][j]>a[i][j-1]){
				sum+=(a[i][j]-a[i][j-1])*num[i];
			}
		}
	}
	cout<<sum<<endl;
}
/*
3
3
4 5 6
1 2 3
4 3 2
1 5 3

3
3
4 5 6
1 2 3
4 3 2
1 5 2

*/
