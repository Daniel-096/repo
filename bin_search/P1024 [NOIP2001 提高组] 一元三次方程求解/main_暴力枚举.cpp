#include<bits/stdc++.h>//18:45 
using namespace std;
float f(float x,float a, float b, float c, float d){//多解？ 
	return a*x*x*x+ b*x*x+c*x+d;
}
int main(){
	
	float step = 0.01;//枚举到3位小数 
	float l = -100+step;
	float a,b,c,d;
	cin>>a>>b>>c>>d;
	int cnt=0;
	while(l<100){//逆天 
//		cout<<f(l, a,b,c,d)*100-100<<endl;
		if(f(l, a,b,c,d)*f(l+step, a,b,c,d)<=0){//异号 
			float x = (l+l+step)/2;
			printf("%.2f", x);
			cnt++;
			if(cnt<3)cout<<" ";
		}
		l+=step;
	}
}
/*
1 -5 -4 20

-2.00 2.00 5.00
*/
