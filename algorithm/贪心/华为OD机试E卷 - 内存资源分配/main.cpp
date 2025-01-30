#include<map>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
map<int, int>mp;
vector<string> split(string s, char c){
	int pre = 0;
	int post = s.find(c);
	vector<string>tokens;
	while(post!=s.npos){
		tokens.push_back(s.substr(pre, post-pre));
		pre = post+1;
		post = s.find(c,pre);
	}
	tokens.push_back(s.substr(pre, post-pre));
	return tokens;
}
int main(){
	string s;
	cin>>s;
	vector<string>tokens= split(s,',');
	for(int i=0;i<tokens.size();i++){
		vector<string>tmp = split(tokens[i],':');
		int size = stoi(tmp[0]), num = stoi(tmp[1]);
		if(mp.count(size)==0){
			mp.insert(make_pair(size,0));
		}
		mp[size]+=num;
	}
	cin>>s;
	vector<string>tar = split(s,',');
	for(int i=0;i<tar.size();i++){//对每个内存大小做判断；可以二分 
		auto it = mp.lower_bound(stoi(tar[i]));
		if(it!= mp.end()){
			cout<<"true";
			int key = (*it).first;
//			cout<<key<<endl;
			mp[key]--;
			if(mp[key]==0){
				mp.erase(it);
			}
		} 
		else{
			cout<<"false";
		}
		if(i<tar.size()-1)cout<<",";
	}cout<<endl;
	
} 
/*
64:2,128:1,32:4,1:128
50,36,64,128,127

64:3,128:1,32:4,1:128
50,64,64,64,64

*/
