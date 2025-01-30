#include<bits/stdc++.h>
using namespace std;
int oNum, xNum, oxNum;
int n;
string str[4]={"ooo*o**--", "o--*o**oo", "o*o*o*--o", "--o*o*o*o"};
string getDp(){
	string s = "";
	for(int i=0;i<oNum;i++){
		s+="o";
	}
	for(int i=0;i<xNum;i++){
		s+="*";
	}
	s+="--";
	for(int i=0;i<oxNum;i++){
		s+="o*";
	}
	return s;
}
string getMid(){
	string s = "";
	for(int i=0;i<oNum-1;i++){
		s+="o";
	}
	s+="--";
	for(int i=0;i<xNum-1;i++){
		s+="*";
	}
	for(int i=0;i<oxNum+1;i++){
		s+="o*";
	}
	return s;
}
int main(){
	cin>>n;
	string tmp;
	oNum=n,xNum=n,oxNum=0;
	while(oNum>=4){
		tmp = getDp();
		cout<<tmp<<endl;
		tmp = getMid();
		cout<<tmp<<endl;
		oxNum++;
		xNum--;
		oNum--;
	}
	for(int i=0;i<4;i++){
		tmp = str[i]+tmp.substr(9);
		cout<<tmp<<endl;
	}
}
/*
7
ooooooo*******--
*/
