#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	ll val;
	string s;
};
int n;
ll getVal(string s){
	int i=0,j=0;
	string tmp = "";
	ll a[4];
	while(i<s.size()){//同时间，不变顺序
		if(s[i]==':'||s[i]=='.'){
//			cout<<tmp<<endl;
			a[j++] = stoi(tmp);
			tmp = "";
		}
		else{
			tmp+=s[i];
		}
		i++;
	}
//	cout<<tmp<<endl;
	a[j] = stoi(tmp);
	
	return a[0]*3600*1000+a[1]*60*1000+a[2]*1000+a[3];
}
Node nodes[(int)1e5+5];
int cmp(Node o1, Node o2){
	return o1.val<o2.val;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>nodes[i].s;
		nodes[i].val = getVal(nodes[i].s);
	}
	sort(nodes, nodes+n, cmp);
	for(int i=0;i<n;i++){
		cout<<nodes[i].s<<endl;
	}
} 
/*
2
01:41:8.9
1:1:09.211


	int i = 3600*1000*23*60;
	ll j = (ll)3600*1000*23*60;
	cout<<i<<endl;
	cout<<j<<endl;
*/
