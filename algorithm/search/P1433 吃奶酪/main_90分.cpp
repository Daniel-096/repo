#include<bits/stdc++.h>
using namespace std;
int n;//x,yҲ����Ϊdouble 
double a[20][20], f[20][34000], ans,x[20], y[20];//2^15-1
double distance(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));//���־��빫ʽ���Ȳ�ͬ�� 
} 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){// 00 Ϊԭ�� 
		cin>>x[i]>>y[i];
	}
	x[0]=0, y[0]=0;//��ʼ��ԭ��λ�� 
	memset(f, 127, sizeof(f));
	ans = f[0][0];//���ans 
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			a[i][j] = distance(x[i], y[i], x[j], y[j]);
			a[j][i] = a[i][j];
		}
	}
	for(int i=1;i<=n;i++){//��ʼ��״̬f (��ԭ����� 
		f[i][1<<(i-1)] = a[0][i];
	}
	for(int k=1;k<(1<<(n));k++){//����㣺ö�����ж�����״̬ 
		for(int i=1;i<=n;i++){//�ڲ㣺ö��ÿ������±� 
			if(k&(1<<(i-1))==0){//״̬����i 
				continue;
			}
			for(int j=1;j<=n;j++){
				if(k&(1<<(j-1))==0||i==j){//״̬����j,��i j�غ� 
					continue;
				}//minΪ�������ߴӲ���i��״̬��j��i 
				f[i][k] = min(f[i][k], f[j][k-(1<<(i-1))]+a[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
//		cout<<f[i][(1<<n)-1]<<endl;//�����ȼӼ�����λ 
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
