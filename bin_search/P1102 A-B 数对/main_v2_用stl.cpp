#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution{
public:
	void solve(int a[], int n, int m){//不要用for去找尾巴，也慢 
		//假设升序 
		ll sum = 0;
		for(int i=0;i<n-1;i++){
			int first = lower_bound(a+i+1, a+n, a[i]+m)-a;//返回第一个大于等于给定值的元素 
			int last = upper_bound(a+i+1, a+n, a[i]+m)-a;//返回了大于给定值的元素 
//			cout<<"first:"<<first<<" last:"<<last<<" i:"<<i<<endl;
			sum+=last-first;//不存在的话，两者相等（n），作差相加为0，少一个if 
		}
		cout<<sum<<endl;
	}
};
int a[200008];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){//tip:输入没说有序 
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
