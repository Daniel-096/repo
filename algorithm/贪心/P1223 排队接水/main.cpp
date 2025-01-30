#include<bits/stdc++.h>
using namespace std;
int n;
struct Node{
	int id;
	int val;
};
Node nodes[1005];
int cmp(Node o1, Node o2){
	return o1.val< o2.val;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>nodes[i].val;
		nodes[i].id = i;
	}
	sort(nodes+1, nodes+n+1, cmp);
	double sum = 0;
	double preSum = 0;
	for(int i=1;i<=n;i++){
		cout<<nodes[i].id;
		if(i<=n-1)cout<<' ';
		sum+=preSum;
		preSum += nodes[i].val;
	}cout<<endl;
	printf("%.2f\n",sum/n);
}
/*
10 
56 12 1 99 1000 234 33 55 99 812
*/
