#include<bits/stdc++.h>
using namespace std;
const int maxN = 100;//自定义一个cmp？ 

bool cmp(string p1, string p2){
	if(p1.size()==p2.size()){
//		bool flag = true;
		for(int i=0;i<p1.size();i++){
			if(p1[i]-p2[i]>0){
				return true;
			}
			else if(p1[i]-p2[i]<0){
				return false;
			}
		} 
	}
	return p1.size()>p2.size();
}
int main(){
	int n;
	cin>>n;
	string maxS;
	int maxId=1;
	cin>>maxS;
	
	for(int i=2;i<=n;i++){
		string tmp;
		cin>>tmp;
		if(tmp.size()>maxS.size()||(tmp.size()==maxS.size() && tmp>maxS)){//if(cmp(tmp, maxS))
			maxS = tmp;
			maxId = i;
		}
		
	}
	cout<<maxId<<endl<<maxS<<endl;
	
}

/*
5
98765
12365
87954
1022356
985678

*/ 
