#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5+5;
int a[maxN];
int main(){
	int L,n,m;
	cin>>L>>n>>m;
	for(int i =0;i<n;i++)
		cin>>a[i];
	int l=1,r = L;
	
	while(l<r){//��һ��
		int mid = l+(r-l)/2;
		int cur = 0,cnt=0, pos=0;//����mid (ò��Ĭ����λ����·��ģ�
//		cout<<"l:"<<l<<" r:"<<r<<" mid:"<<mid<<endl; 
		while(cur<n-1){
			if(pos==0){
				pos = a[cur];//û�о���ʱ�������븳ֵ 
			}
			if(a[cur+1]-pos>mid){//�м�ֵ 
				cnt++;//�ű� 
				pos += mid;//��λ�� 
			}
			else {
				pos=0;
				cur++;
			}
		}
		if(cnt>m){
			l = mid+1;
		}
		else{
			r = mid;
		}
	}
	cout<<l<<endl;
} 
/*
101 2 1
0 101
*/
