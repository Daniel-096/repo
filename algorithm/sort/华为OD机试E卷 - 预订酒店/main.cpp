#include<bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	int tar;
};
const int maxN = 1e6+5;
Node nodes[maxN];
int cmp(Node o1, Node o2){
	if(abs(o1.val-o1.tar) == abs(o2.val-o2.tar)){
		return o1.val < o2.val;
	}
	return abs(o1.val-o1.tar) < abs(o2.val-o2.tar);  //当酒店差价一致时，先选低价。。 
}
int cmp2(Node o1, Node o2){
	return o1.val<o2.val;
}
int main(){
	int n,k,x;

	cin>>n>>k>>x;
	for(int i=0;i<n;i++){
		cin>>nodes[i].val;
		nodes[i].tar = x;
	}
	sort(nodes,nodes+n,cmp);
	sort(nodes,nodes+k,cmp2);
	for(int i=0;i<k;i++){
		cout<<nodes[i].val;
		if(i<k-1)cout<<" ";
	}cout<<endl;
}
/*
5 1 6
0 5 7 10 11
*/
