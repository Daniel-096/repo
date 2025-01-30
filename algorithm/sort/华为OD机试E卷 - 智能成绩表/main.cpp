#include<bits/stdc++.h>
using namespace std;
string s[20], tar;
string zongfen = "zongfen";
struct Node{
	unordered_map<string, int> mp;
	string name;
	string tar;
};
Node nodes[105];
int n,m;
//自定义排序
int cmp(Node o, Node s){//Q 总分参数穿不进去？ 
	if(o.mp[tar]==s.mp[tar]){
		return o.name<s.name;
	}
	return o.mp[tar]>s.mp[tar];
} 
int main(){
	cin>>n>>m;
	for(int j=0;j<m;j++){
		cin>>s[j];
	}
	for(int i=0;i<n;i++){
		Node tmp;
		cin>>tmp.name;
		int sum = 0;
		for(int j=0;j<m;j++){
			int num;
			cin>>num;
			tmp.mp.insert(make_pair(s[j],num));
			sum+=num;
		}
		tmp.mp.insert(make_pair(zongfen,sum));
		nodes[i] = tmp;
	}
	cin>>tar;
	bool flag=false;
	for(int i=0;i<n;i++){
		if(s[i]==tar){
			flag = true;
			break;
		}
	}
	if(!flag){
		tar = zongfen;
	}
	for(int i=0;i<n;i++){
		nodes[i].tar = tar;//写入成员 
	} 
	sort(nodes, nodes+n,cmp);
	for(int i=0;i<n;i++){
		cout<<nodes[i].name;
		if(i<n-1)cout<<' ';
	}cout<<endl;
	
}
/*
3 2
yuwen shuxue
fangfang 95 90
xiaohua 88 98
minmin 100 82
shuxue

*/
