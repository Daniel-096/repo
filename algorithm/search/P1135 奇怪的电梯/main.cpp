#include<bits/stdc++.h>
using namespace std;
int a[205];
int w[205];//��ť 
int n, l, r;//��1¥��ʼ 
bool check(int x){
	return x>0&&x<=n&&a[x]<0;
}
int main(){

	memset(a, -1, sizeof(a));//-1��ʾû���� 
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	queue<int>q;
	q.push(l);
	a[l]=0;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		int x[2];
		x[0] = cur+w[cur], x[1] = cur-w[cur];
		for(int i=0;i<2;i++){
			if(check(x[i])){//��Խ����û����
				a[x[i]] = a[cur]+1;
				q.push(x[i]);
			}
			if(x[i]==r){
				cout<<a[x[i]]<<endl;
				return 0;
			}
		}
	} 
	cout<<"-1"<<endl;
}
/*
5 1 5
3 3 1 2 5

5 1 5
1 1 1 0 5
*/
