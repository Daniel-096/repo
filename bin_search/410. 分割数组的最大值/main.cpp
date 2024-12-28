#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
	int splitArray(vector<int>& v, int k){
		int l = v.front();
		int r = 0;
		for(auto p=v.begin();p!=v.end();p++){
			l = max(*p, l);
			r+= *p;
		}
		while(l<r){
			int mid = l+(r-l)/2, cnt=0, tmp=0;
			for(auto p=v.begin();p!=v.end();p++){
				if(tmp+*p>mid){
					cnt++;
					tmp=0;
				}
				tmp+=*p;
			}
			if(tmp>0)cnt++;
			if(cnt>k){
				l=mid+1;
			}
			else{
				r = mid;
			}
		}
		return l;
	}
};
int main(){
	int n;
	cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	int k;
	cin>>k;
	cout<<Solution().splitArray(v,k);
//	for(auto it = v.begin();it!=v.end();it++){//dev¿ÉÓÃauto c11 
//		cout<<*it<<endl;
//	}
}
/*

5
1 2 3 4 5
2
*/
