#include<bits/stdc++.h>
using namespace std;
const int maxN = 505;
int a[maxN][maxN],n,m,step[4][2]={{1,0},{-1,0},{0,1},{0,-1}}, noNum = 0,level=0;
bool vis[maxN][maxN];
struct Node{
	int x;
	int y;
};
queue<Node>q;
vector<string>split(string s,char c){
	vector<string>tokens;
	int pre = 0;
	int end = s.find(c);
	while(end!=s.npos){
//		cout<<s.substr(pre, end-pre)<<endl;
		tokens.push_back(s.substr(pre, end-pre));
		pre = end+1;
		end = s.find(c, pre);
	}
	tokens.push_back(s.substr(pre));
	return tokens;
}
void bfs(){//1 把所有为yes的点入队，并标为访问 
	while(!q.empty()&&noNum){//队不空，且去掉最后一层 
//		cout<<"level:"<<level<<endl;
		int len = q.size();
		while(len--){
			Node cur= q.front();
			q.pop();
//			cout<<"cur.x:"<<cur.x<<" cur.y:"<<cur.y<<endl;
			for(int i=0;i<4;i++){
				int dx = cur.x+step[i][0];
				int dy = cur.y+step[i][1];
				if(!vis[dx][dy]&&a[dx][dy]==2){
//					cout<<"dx:"<<dx<<" dy:"<<dy<<endl;
					vis[dx][dy]=true;
					noNum--;
					Node tmp;
					tmp.x=dx;
					tmp.y=dy;
					q.push(tmp);
				}
			}
		}
		level++;

	}
} 
int main(){
	string s;
	memset(a, -1, sizeof(a));
	cin>>n;
	cin.ignore();//配合在getline前用 
	int i=1;

	while(n--){
		getline(cin,s);
		auto p = split(s,' ');
		m = p.size();
		for(int j=0;j<p.size();j++){

			if(p[j]=="YES"){
				a[i][j+1]=1;
				Node tmp;
				tmp.x=i;
				tmp.y=j+1;
				q.push(tmp);//入队并标记 
				vis[i][j+1]=true;
			}
			else if(p[j]=="NO"){
				a[i][j+1]=2;
				noNum++;
			}//Na==-1
		}
		i++;
	}
	n = i-1;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<a[i][j]<<' ';
//		}cout<<endl;
//	}
	bfs();
	if(noNum==0){
		cout<<level<<endl;
	}
	else{
		cout<<"-1"<<endl;
	}
//	while(cin>>s){
//		
//	}
	
}

/*
3
YES YES NO
NO NO NO
NA NO YES

2

3
YES YES NO
NO NO NO
YES NO NO

2

4
YES NO NO NO
NO NO NO NO
NO NO NO NO
NO NO NO NO

6

1
NO NA

-1 

4
YES NO NO YES
NO NO YES NO
NO YES NA NA
YES NO NA NO

-1 
*/
