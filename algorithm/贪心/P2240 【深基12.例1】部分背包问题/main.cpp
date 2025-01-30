#include<bits/stdc++.h>
using namespace std;
struct Node{
	int num;//个数 
	double val;//单价 
};
int n,m;
Node nodes[105];
int cmp(Node o1, Node o2){
	return o1.val>o2.val;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>nodes[i].num>>nodes[i].val;
		nodes[i].val = nodes[i].val/nodes[i].num;
	}
	sort(nodes, nodes+n, cmp);
	double sum = 0;
	int j=0;
	while(m&&j<n){
		if(m-nodes[j].num>=0){
			m-=nodes[j].num;
			sum+=nodes[j].num*nodes[j].val;
		}
		else{
			sum+=m*nodes[j].val;
			m = 0;
		}
		j++;
	}
	printf("%.2f\n",sum);
		
	
}
/*
4 50
10 60
20 100
30 120
15 45
*/
