#include<bits/stdc++.h>
using namespace std;
int n;//x,y也可以为double 
double a[20][20], f[20][34000], ans,x[20], y[20];//2^15-1
double distance(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));//两种距离公式精度不同？ 
} 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){// 00 为原点 
		cin>>x[i]>>y[i];
	}
	x[0]=0, y[0]=0;//初始化原点位置 
	memset(f, 127, sizeof(f));
	ans = f[0][0];//最大ans 
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			a[i][j] = distance(x[i], y[i], x[j], y[j]);
			a[j][i] = a[i][j];
		}
	}
	for(int i=1;i<=n;i++){//初始化状态f (到原点距离 
		f[i][1<<(i-1)] = a[0][i];
	}
	for(int k=1;k<(1<<(n));k++){//最外层：枚举所有二进制状态 
		for(int i=1;i<=n;i++){//内层：枚举每个点的下标 
			if(k&(1<<(i-1))==0){//状态不含i 
				continue;
			}
			for(int j=1;j<=n;j++){
				if(k&(1<<(j-1))==0||i==j){//状态不含j,或i j重合 
					continue;
				}//min为本身，或者从不含i的状态沿j到i 
				f[i][k] = min(f[i][k], f[j][k-(1<<(i-1))]+a[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
//		cout<<f[i][(1<<n)-1]<<endl;//逆天先加减再移位 
		ans = min(ans, f[i][(1<<n)-1]);
	}
	printf("%.2f\n", ans);
	
}
/*
4
1 1
1 -1
-1 1
-1 -1
*/
