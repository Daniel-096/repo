#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e4;
int m,n,a[maxN];
vector<string>split(string s, char c){
	vector<string>tokens;
	int end = s.find(c);
	int pre = 0;
	while(end!=s.npos){
		tokens.push_back(s.substr(pre, end-pre));
		pre = end+1;
		end = s.find(c,pre);
	}
	tokens.push_back(s.substr(pre));
	return tokens;
}

bool dfs(vector<int>&v, int index, int tar){
	if(index>=n){//1 base case 
		return true;
	}
	for(int i=0;i<m;i++){
		if(v[i]+a[index]<=tar){
			v[i]+=a[index];
			if(dfs(v,index+1, tar)){//×ÓÎÊÌâ 
				return true;
			}
			v[i]-=a[index];
		}
		if(v[i]==0||v[i]+a[index]==tar){
			break;
		}
	}
	
	return false;
}
bool check(int tar){
	vector<int>v(m,0);
	return dfs(v,0,tar);
}
int main(){
	string s;
	getline(cin,s);
	cin>>m;
	auto tokens = split(s, ' ');
	n = tokens.size();
	int l=0, r=0;
	for(int i=0;i<n;i++){
		a[i] = stoi(tokens[i]);
		r+=a[i];
		l = max(a[i],l);
	}
	sort(a,a+n,greater<int>());
	while(l<r){
		int mid = l+(r-l)/2;
//		cout<<"l:"<<l<<" mid:"<<mid<<" r:"<<r<<endl;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid+1;
		}
	}
	cout<<l<<endl;
	
}
/*
7 13 19 25 31 37 43 49 55 61 67 73 79 85 91 97 103 109 115 121
6
6 2 7 7 9 3 2 1 3 11 4
2
*/
 
