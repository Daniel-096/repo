#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+5;
typedef long long ll;
int a[maxN];
int w, m, n;
double f(double rate){
	double sum=w;
	for(int i=0;i<n;i++){
		sum = sum*(100+rate)/100-m;//Ҫ��ȥÿ�µĻ��� 
	}
	return sum;
}
int main(){

	cin>>w>>m>>n;
	double l=0, r = 300;//ģ����ӽ� 
	while(l<r-0.001){
		double mid = l+(r-l)/2;
		if(f(mid)>0){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	double fl = f(l), fr = f(r);
	double ans;
	if(fl>0){
		ans = l;
	}
	else if(fr<0){
		ans = r;
	}
	else{
		ans = abs(fl)>fr?r:l;
	}
	printf("%.1f", ans);
}
/*
1000 100 12
*/
