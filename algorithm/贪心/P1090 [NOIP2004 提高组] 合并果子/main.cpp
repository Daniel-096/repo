#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue> 
#include<vector>
using namespace std;
int n;
int sum = 0;//×îÐ¡¶Ñ£¿£¿ 
int main(){
	priority_queue<int, vector<int>, greater<int>>pq;
	cin>>n;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		pq.push(tmp);
	}
	if(n==1){
		cout<<pq.top()<<endl;
		return 0;
	}
	while(pq.size()>1){
//		cout<<pq.top()<<endl;
		int cur = pq.top();
		pq.pop();
		cur+=pq.top();
		pq.pop();
		sum+=cur;
		pq.push(cur);
	}
	cout<<sum<<endl;
}
/*
3 
1 2 9 

1
10

4
3 4 5 7
*/
