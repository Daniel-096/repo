#include<bits/stdc++.h>
using namespace std;
map<string, int>mp;
int main(){
	int n;
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++){
		string tmp;
		getline(cin,tmp);
		if(mp.count(tmp)){
			mp[tmp]++;
		}
		else{
			mp.insert(make_pair(tmp,1));
		}
	}
	string pre = "";
	int cnt = 0;
	for(auto p = mp.begin();p!=mp.end();p++){
		string cur = (*p).first.substr(0,19);
		if(pre!=cur){
			pre = cur;
			cnt+= (*p).second;
		}
	}
	cout<<cnt<<endl;
	
}
/*
5
2019-01-01 00:00:00.004
2019-01-01 00:00:00.004
2019-01-01 00:00:01.006
2019-01-01 00:00:01.006
2019-01-01 00:00:01.005

*/
