#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution{
public:
	int find_first(int a[], int l, int r, int tar){
//		cout<<"test"<<endl;
		while(l<r){
			int mid = l+(r-l)/2;
			if(a[mid]>tar){
				r = mid-1;
			}
			else if(a[mid]<tar){
				l = mid+1;
			}
			else{
				r=mid;
			}	
		}
		if(tar==a[l]){//找不到 
			return l;
		}
		else{
			return -1;
		}
	}
	int find_last(int a[], int l, int r, int tar){
		while(l<r){
			int mid = l+(r-l+1)/2;
			if(a[mid]>tar){
				r = mid-1;
			}
			else if(a[mid]<tar){
				l=mid+1;
			}
			else{
				l=mid;
			}	
		}
		if(tar==a[l]){//找不到 
			return l;
		}
		else{
			return -1;
		}
	}
	void solve(int a[], int n, int m){//不要用for去找尾巴，也慢 
		//假设升序 

		ll sum = 0;
		for(int i=0;i<n-1;i++){
			int first = find_first(a, i+1, n-1, a[i]+m);
			int last = find_last(a, i+1, n-1, a[i]+m);
			if(first!=-1){
				sum+=last-first+1;
			}
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
