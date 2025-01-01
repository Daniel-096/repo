#include<bits/stdc++.h>
using namespace std;
const int maxN = 5e6+5;
int a[maxN];
int main(){
	int n, k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	nth_element(a, a+k, a+n);
	cout<<a[k]<<endl;
	
}


/*
5 1
4 3 2 1 5
*/
