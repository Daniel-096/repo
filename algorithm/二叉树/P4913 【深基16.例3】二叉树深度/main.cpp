#include<bits/stdc++.h>
using namespace std;
struct Node{
	int l;
	int r;

};
const int maxN = 1e6+5;
int n, maxH=0;
Node tree[maxN];//数组模拟二叉树 
void dfs(Node cur, int h){
	maxH = max(h, maxH);
	if(cur.l!=0)dfs(tree[cur.l],h+1);
	if(cur.r!=0)dfs(tree[cur.r],h+1);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tree[i].l>>tree[i].r;
	}
	dfs(tree[1],1);
	cout<<maxH<<endl;
}
/*
7
2 7
3 6
4 5
0 0
0 0
0 0
0 0

5
2 3
0 0
4 5
0 0
0 0

1
0 0

*/
