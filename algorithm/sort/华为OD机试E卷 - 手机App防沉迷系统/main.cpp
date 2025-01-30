#include<bits/stdc++.h>
using namespace std;
struct Node{
	string  name;
	int level;
	int beginTime[2];
	int endTime[2];
};
int n;
vector<Node>nodes;
void getTime(int *a){
	string tmp;
	cin>>tmp;//09:00
	a[0] = stoi(tmp.substr(0,2));
	a[1] = stoi(tmp.substr(3,2));
}
int timeVal(int *a){
	return a[0]*60+a[1];
}
bool change(Node o1, Node o2){
	if(o1.level==o2.level){
		return timeVal(o1.beginTime)<timeVal(o2.beginTime);
	}
	return o1.level>o2.level;
}
int main(){
	cin>>n;
	nodes.resize(n);
	for(int i=0;i<n;i++){
		cin>>nodes[i].name>>nodes[i].level;
		getTime(nodes[i].beginTime);
		getTime(nodes[i].endTime);
	}
	int tar[2];
	getTime(tar);
//	cout<<tar[0]<<" "<<tar[1];
	Node ans;
	ans.name = "NA";
	
	for(int i=0;i<n;i++){//不用删 
		if(timeVal(nodes[i].beginTime)<timeVal(nodes[i].endTime) && timeVal(nodes[i].beginTime)<=timeVal(tar) &&
		timeVal(tar)<timeVal(nodes[i].endTime)){
			if(ans.name=="NA"||!change(ans, nodes[i])){
				ans = nodes[i];
			}
		}
	}
	cout<<ans.name<<endl;
}
/*
2
App1 1 09:00 10:00
App2 2 09:10 09:30
09:20

1
App1 1 09:00 10:00
09:30

2
App1 1 09:00 10:00
App2 2 09:10 09:30
09:50


1
App1 1 09:00 10:00
19:30
//相等 
2
App1 1 09:00 10:00
App2 1 09:10 09:30
09:00

2
App1 2 09:00 10:00
App2 2 09:10 09:30
09:30

2
App1 3 19:00 10:00
App2 2 09:10 09:50
09:30
*/

