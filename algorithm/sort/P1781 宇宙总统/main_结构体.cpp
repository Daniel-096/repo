#include<bits/stdc++.h>
using namespace std;
const int maxN = 100;//自定义一个cmp？ 
struct P{
	string s;
	int id;
};
bool cmp(P p1, P p2){
	if(p1.s.size()==p2.s.size()){
//		bool flag = true;
		for(int i=0;i<p1.s.size();i++){
			if(p1.s[i]-p2.s[i]>0){
				return true;
			}
			else if(p1.s[i]-p2.s[i]<0){
				return false;
			}
		} 
	}
	return p1.s.size()>p2.s.size();
}
int main(){
	int n;
	cin>>n;
	P p[maxN];
	for(int i=0;i<n;i++){
		cin>>p[i].s;
		p[i].id=i+1;
	}
	sort(p, p+n, cmp);
	cout<<p[0].id<<endl<<p[0].s<<endl;
	
}