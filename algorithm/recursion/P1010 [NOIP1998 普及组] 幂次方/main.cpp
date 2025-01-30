#include<bits/stdc++.h>
using namespace std;
int n;
string ans="";
string getStr(int x){
	if(x==1)return "2";
	else return "2("+to_string(x)+")";
}
int getNum(int x){//cnt转原数 
	return int(pow(2, x)); 
}
string dfs(int x, bool f){
//	cout<<"cur:"<<x<<endl;
	//1 拆分
	stack<int>st;
	int cnt=0;
	string s="";
	if(f)s+="2(";
	while(x!=1){
		int tmp = x%2;
		if(tmp==1){
//			st.push(int(pow(2, cnt)));
			st.push(cnt);
		}
		cnt++;
		x /=2;
	}
	st.push(cnt);
	while(!st.empty()){
		int cur = st.top();
		if(cur>=3){//3次密可拆 
			s+=dfs(cur,true);
		}
		else s+=getStr(cur);
		st.pop();
		if(!st.empty())s+="+";
	}
	if(f)s+=")";
	return s;
}
int main(){
	cin>>n;
//	cout<<int(pow(2, 0))<<endl;
	cout<<dfs(n, false)<<endl;
	
}
/*
1315
2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
*/
