#include<bits/stdc++.h>
using namespace std;
string s;
stack<int>st;//数字栈 
stack<string>preSt;//前缀栈 
string strNum;
int getNum(int i){//返回下标 
	strNum = "";
	while(s[i]>='0'&&s[i]<='9'){
		strNum+=s[i];
		i++;
	}
	st.push(stoi(strNum));
	return i;
}
string getStr(string s){//倍数复制 
	string sum = "";
	int cur = st.top();
	st.pop();
	while(cur--){
		sum+=s;
	}
	return sum;
}
int main(){
	cin>>s;
	int i=0;
	string tmpStr = "";
	while(i<s.size()){//遍历 
		if(s[i]>='A'&&s[i]<='Z'){//没有数字，且为字母 
			if(st.empty()){
				cout<<s[i];
			}
			else{//存字母 
				tmpStr+=s[i];
			}
			
		}
		else if(s[i]=='['){//找数字
			if(!st.empty()&&tmpStr.size()>0){//有前缀，存好 
				preSt.push(tmpStr);
				tmpStr = "";
			} 
			i = getNum(i+1);
			continue;//不用自增 
			//找字符串 
		}
		else{//']'
			tmpStr = getStr(tmpStr);
			if(!preSt.empty()){//有前缀 
				string s1 = preSt.top();
				preSt.pop();
				tmpStr = s1+tmpStr;
			}
			//无数字，输出
			if(st.empty()){
				cout<<tmpStr;
				tmpStr = "";
			} 
		}
		i++;
	}
}
/*
AC[3FUN]
AC[2[2UN]]AC
//前后缀 
AC[2FUN[2AI]CK]

*/
