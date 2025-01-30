#include<bits/stdc++.h>
using namespace std;

bool vis[200];
int main(){
	string s;
	cin>>s;
	memset(vis,false, sizeof(vis));
	for(int i=0;i<s.size();i++){
		if(s[i]==')'){
			for(int j=i-1;j>=0;j--){//逆天[被标记过的也要跳过 
				if(s[j]=='['){//&&vis[j]==false
					break;
				}
				else if(s[j]=='('&&vis[j]==false){
					vis[j]=true;
					vis[i]=true;
					break;
				}
			}
		}
		else if(s[i]==']'){
			for(int j=i-1;j>=0;j--){
				if(s[j]=='('&&vis[j]==false){
					break;
				}
				else if(s[j]=='['&&vis[j]==false){
					vis[j]=true;
					vis[i]=true;
					break;
				}
			}
		}
	}
	for(int i=0;i<s.size();i++){
		if(!vis[i]){
			if(s[i]=='('||s[i]==')')cout<<"()";
			else cout<<"[]";
		}
		else cout<<s[i];
	}
	
}
/*
([()
([)
)(
())
([(]((
([)])
(]))
*/
