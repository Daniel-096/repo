#include<bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
string origin[100], trans[100];
unordered_map<string,int>mp;
struct Node{
	string s;
	int cnt;
};
string transfer(string s, int i, int j){
	string ans = "";
	if(i+origin[j].size()>s.size()){//��ת������ ������ 
		return ans;
	}
	for(int k=0;k<origin[j].size();k++){//��λ�Ƚ� 
		if(s[i+k]!=origin[j][k])return ans;
	}
	ans = s.substr(0, i);//ǰ׺
	ans+= trans[j];
	ans+= s.substr(i+origin[j].size());
	return ans; 
}
int main(){
	cin>>a>>b;
	m=0;
	while(cin>>origin[m]>>trans[m])m++;
//	for(int i=0;i<m;i++){
//		cin>>origin[i]>>trans[i];
//	}
//	cout<<m<<endl;
	queue<Node>q;
	Node tmp;
	tmp.s = a;
	tmp.cnt = 0;
	q.push(tmp);
	int ans;
	while(!q.empty()){
		Node cur = q.front();
		q.pop();
		if(mp.count(cur.s)==1){//��֦ 
			continue;
		}
		else{
			mp.insert(make_pair(cur.s,1));//��¼ 
		}
		if(cur.s==b){//��ans 
			ans = cur.cnt;
			break;
		}
		for(int i=0;i<cur.s.size();i++){
			for(int j=0;j<m;j++){
				string tmpS = transfer(cur.s,i,j);//ת���ַ���
				if(tmpS!=""){
//					cout<<tmpS<<endl;
					tmp.s = tmpS;
					tmp.cnt = cur.cnt+1;
					q.push(tmp);
				}
			}
		}
	}
	if(ans==0||ans>10)cout<<"NO ANSWER!"<<endl;
	else cout<<ans<<endl;
}
/*
abcd xyz
abc xu
ud y
y yz
*/
