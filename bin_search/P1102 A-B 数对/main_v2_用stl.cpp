#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution{
public:
	void solve(int a[], int n, int m){//��Ҫ��forȥ��β�ͣ�Ҳ�� 
		//�������� 
		ll sum = 0;
		for(int i=0;i<n-1;i++){
			int first = lower_bound(a+i+1, a+n, a[i]+m)-a;//���ص�һ�����ڵ��ڸ���ֵ��Ԫ�� 
			int last = upper_bound(a+i+1, a+n, a[i]+m)-a;//�����˴��ڸ���ֵ��Ԫ�� 
//			cout<<"first:"<<first<<" last:"<<last<<" i:"<<i<<endl;
			sum+=last-first;//�����ڵĻ���������ȣ�n�����������Ϊ0����һ��if 
		}
		cout<<sum<<endl;
	}
};
int a[200008];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){//tip:����û˵���� 
		cin>>a[i];
	}
	sort(a, a+n);
	Solution().solve(a, n, m);
}
/*

5 1
1 1 2 2 3


5 1
2 2 3 1 1


6

4 1
1 1 2 3

4

4 3
1 1 2 3

0
*/
