#include<bits/stdc++.h>
using namespace std;
const int maxN = 25;
int vis[maxN], n, ans=0;
string s[maxN];//dfs 
int link_len(string tail, string head){

	for(int i=1;i<min(tail.size(), head.size());i++){//��㳤�ȣ��ڲ�Ƚ� ,����ȫ���ص�����ȡ���� 
		bool flag = true;
		for(int j=0;j<i;j++){
			if(head[j]!=tail[tail.size()+j-i]){
				flag=false;
				break;
			}
		}
		if(flag)return i;
	}
	return 0;
}
void dfs(string tail, int len){
	ans = max(ans, len);//ˢ�½�
	for(int i=0;i<n;i++){
		if(vis[i]<2){
			int c = link_len(tail, s[i]);
//			cout<<tail<<" "<<s[i]<<" "<<c<<endl;
			if(c>0){
				vis[i]++;
				dfs(s[i], len+s[i].size()-c);
				vis[i]--;
			}
		}
	} 
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	memset(vis, 0, sizeof(vis));
	cin>>s[n];
	s[n] = "#"+s[n];
	dfs(s[n],1);
	cout<<ans<<endl;
	
}
/*
5
at
touch
cheat
choose
tact
a
*/
