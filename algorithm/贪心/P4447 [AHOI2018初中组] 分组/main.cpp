#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5+5;
int n,q[maxN],size[maxN],a[maxN],top=0;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		int id = lower_bound(q,q+top,a[i])-q;//返回1一个迭代器，减掉q为下标 //top=0,初始范围为0 
		while(id<top&&q[id+1]==a[i])id++;//找最后1个 
		if(id>top||q[id]!=a[i]){//id过大或者没找到id都要开新租 
			q[top]=a[i]+1;//开新组
			size[top++]=1; 
		}
		else{
			size[id]++;
			q[id]++;
		}
	}
	int ans = size[0];
	for(int i=0;i<top;i++){
		ans = ans>size[i]?size[i]:ans;
	}
	cout<<ans<<endl;
	return 0;
}
/*
7
4 5 2 3 -4 -3 -5
6
4 5 2 3 2 3
3
1 3 5
4
2 3 4 5
*/