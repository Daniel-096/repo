#include<algorithm>
#include<cstdio>
#include<iostream>
#include<unordered_set>
using namespace std;
struct Node{
	int l;
	int r;
};
int n;
const int maxN = 1e6+5;
Node nodes[maxN];
int cmp(Node o1, Node o2){
	return o1.r<o2.r;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>nodes[i].l>>nodes[i].r;
	}
	sort(nodes,nodes+n,cmp);
	int end = 0;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(nodes[i].l>=end){
			cnt++;
			end = nodes[i].r;
		}
	}
	cout<<cnt<<endl;
}

/*
3
0 2
2 4
1 3
*/
