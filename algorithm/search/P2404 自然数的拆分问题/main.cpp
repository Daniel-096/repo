#include<bits/stdc++.h>
using namespace std;
int a[100];
int n;
void dfs(int x, int len){//�Ե����� 
	for(int j = a[len-1];j<=x;j++){ //��j==xʱ���൱�ڲ����ָ� 
		if(j<n){//���������ֵn (���⵱x==nʱ��jȡ��n���������⣩ 
			a[len]=j;
			x-=j;
			if(x==0){
				for(int i=1;i<=len;i++){
					cout<<a[i];
					if(i<len)cout<<"+";
				}
				cout<<endl;
			}
			else dfs(x, len+1);
			x+=j;
		}
	}
}
int main(){
	cin>>n;
	a[0] = 1;//��ֵ 
	dfs(n, 1);
}
/*
3
1+1+1
1+2
*/
