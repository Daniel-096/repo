#include<bits/stdc++.h>
using namespace std;
string s;
stack<int>st;//����ջ 
stack<string>preSt;//ǰ׺ջ 
string strNum;
int getNum(int i){//�����±� 
	strNum = "";
	while(s[i]>='0'&&s[i]<='9'){
		strNum+=s[i];
		i++;
	}
	st.push(stoi(strNum));
	return i;
}
string getStr(string s){//�������� 
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
	while(i<s.size()){//���� 
		if(s[i]>='A'&&s[i]<='Z'){//û�����֣���Ϊ��ĸ 
			if(st.empty()){
				cout<<s[i];
			}
			else{//����ĸ 
				tmpStr+=s[i];
			}
			
		}
		else if(s[i]=='['){//������
			if(!st.empty()&&tmpStr.size()>0){//��ǰ׺����� 
				preSt.push(tmpStr);
				tmpStr = "";
			} 
			i = getNum(i+1);
			continue;//�������� 
			//���ַ��� 
		}
		else{//']'
			tmpStr = getStr(tmpStr);
			if(!preSt.empty()){//��ǰ׺ 
				string s1 = preSt.top();
				preSt.pop();
				tmpStr = s1+tmpStr;
			}
			//�����֣����
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
//ǰ��׺ 
AC[2FUN[2AI]CK]

*/
