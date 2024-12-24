#include<bits/stdc++.h>//18:45 
using namespace std;//float 和 double？ 
float a,b,c,d,x1,x2, step = 1e-6;
float f(float x){//多解？ 
	return a*x*x*x+ b*x*x+c*x+d;
}
int main(){
	cin>>a>>b>>c>>d;
	//预处理为a大于0
	if(a<0){
		a = -a, b = -b, c= -c, d = -d;
	} 
	float a1 = a*3, b1 = b*2, c1=c;
	x1 = (-b1-sqrt(b1*b1 - 4*a1*c1))/(2*a1);
	x2 = (-b1+sqrt(b1*b1 - 4*a1*c1))/(2*a1);
	float num[4];
	num[0] = -100, num[1] = x1, num[2] = x2, num[3]=100;
	for(int i=0;i<3;i++){
		float l = num[i], r = num[i+1];//二分精确值
//		cout<<"l:"<<f(l,a,b,c,d)<<" r:"<<f(r,a,b,c,d)<<endl;
		while(l+0.001<=r){//控3位 
			float mid = l+(r-l)/2;
			if(f(mid)*f(r)>=0){//增区间(其实是万用型 
				r = mid;
			}
			else{
				l = mid;
			}
		}
		printf("%.2f", l);
		if(i<2)cout<<" ";
	}
}
/*
1 -5 -4 20

-2.00 2.00 5.00
*/
