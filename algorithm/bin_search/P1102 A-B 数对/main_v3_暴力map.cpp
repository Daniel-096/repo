#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution{
public:
	void solve(int a[], int n, int m){//不要用for去找尾巴，也慢 
		//打表 
		ll sum = 0;
		map<int, int>mp;
		for(int i=0;i<n;i++){
			if(mp.find(a[i])==mp.end()){
				mp.insert(pair<int, int>(a[i], 0));
			}
			mp[a[i]]++;
		}
		for(auto p = mp.begin();p!=mp.end();p++){
			auto tmp = mp.find(p->first-m);
			if(tmp!=mp.end()){
				sum+=ll(tmp->second )* ll(p->second);
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
