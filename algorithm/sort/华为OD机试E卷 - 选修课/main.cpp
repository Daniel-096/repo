#include<bits/stdc++.h>
using namespace std;
unordered_map<string, int>mp;
struct Node{
	string classNum;//01202
	string stNum;//021
	int val;//0,100
};
vector<Node>nodes;
vector<string> getToken(string s){
	int pre = 0;
	int end = s.find(';');
	int n=0;
	vector<string>tokens;
	while(end != s.npos){
		tokens.push_back(s.substr(pre, end-pre));
		pre = end+1;
		end = s.find(';', pre);
	}
	tokens.push_back(s.substr(pre));
	return tokens;
}
int cmp(Node o1, Node o2){
	if(o1.classNum==o2.classNum){
		if(o1.val==o2.val){
			return o1.stNum<o2.stNum;
		}
		return o1.val>o2.val;
	}
	return o1.classNum<o2.classNum;
}
int main(){
	string s;
	cin>>s;//c++的字符串分割 
	auto tokens = getToken(s);
	for(int i=0;i<tokens.size();i++){
		Node cur;
		cur.classNum = tokens[i].substr(0, 5);
		cur.stNum = tokens[i].substr(5, 3);
		cur.val = stoi(tokens[i].substr(9))-1000;
		mp.insert(make_pair(cur.classNum+cur.stNum,i));
		nodes.push_back(cur);
	}
	cin>>s;
	tokens = getToken(s);
	for(int i=0;i<tokens.size();i++){
//		cout<<tokens[i]<<endl;
		if(mp.count(tokens[i].substr(0,8))){
			nodes[mp[tokens[i].substr(0,8)]].val += stoi(tokens[i].substr(9))+1000;
//			cout<<nodes[mp[tokens[i].substr(0,8)]].val<<endl;
		}
	}
	int j=0;
	while(j<nodes.size()){
		if(nodes[j].val<0){
			nodes.erase(nodes.begin()+j);
		}
		else{
			j++;
		}
	}
	sort(nodes.begin(),nodes.end(),cmp);
	//特判全不符合
	if(nodes.size()==0){
		cout<<"NULL"<<endl;
		return 0;
	}
	string preStr = nodes[0].classNum;
	string ans;
	ans+=nodes[0].classNum+"\n";
	for(int i=0;i<nodes.size();i++){
		if(preStr!=nodes[i].classNum){
			preStr = nodes[i].classNum;
			ans.erase(ans.size()-1);
			ans+="\n"+preStr+"\n";
		}
		ans+=nodes[i].classNum+nodes[i].stNum+";";
	}
	ans.erase(ans.size()-1);
//	ans+="\n";
	cout<<ans;

//	cin>>s;//c++的字符串分割 
//	pre = 0;
//	end = s.find(';');
//	while(end != s.npos){
//		tmp = s.substr(pre, end-pre);
//		if(mp.count(tmp.substr(0,8))){//存在 
//			nodes[mp[tmp.substr(0,8)]].val += 1000+stoi(tmp.substr(9));
//		}
//		pre = end+1;
//		end = s.find(';', pre);
//	}
//	tmp = s.substr(pre);
//	if(mp.count(tmp.substr(0,8))){//存在 
//		nodes[mp[tmp.substr(0,8)]].val += 1000+stoi(tmp.substr(9));
//	}
//	pre = end+1;
//	end = s.find(';', pre);
//	//排序 （含无效项） 
//	sort(nodes, nodes+n,cmp);
//	//特判全不符合
//	if(nodes[0].val<0){
//		cout<<"NULL"<<endl;
//		return 0;
//	}
//	string preStr = nodes[0].classNum;
//	cout<<nodes[0].classNum<<endl;
//	for(int i=0;i<n;i++){
//		if(preStr!=nodes[i].classNum){
//			preStr = nodes[i].classNum;
//			cout<<endl<<preStr<<endl;
//		}
//		cout<<nodes[i].classNum+nodes[i].stNum<<":"<<nodes[i].val<<";";
//	}
	
}
/*
01202021,75;01201033,95;01202008,80;01203006,90;01203088,100
01202008,70;01203088,85;01202111,80;01202021,75;01201100,88

01202
01202008;01202021
01203
01203088

*/
