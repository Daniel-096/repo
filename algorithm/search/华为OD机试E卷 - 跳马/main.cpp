#include<bits/stdc++.h>
using namespace std;
const int maxN = 505;
const int notFind = 1e9;
int a[maxN][maxN],sumM = 0,n,m,ans=notFind,step[8][2]={{1, 2}, {2, 1},{-1, -2}, {-2, -1},
         {-1, 2}, {-2, 1}, {1, -2}, {2, -1}};
struct Node{
	int x;
	int y;
	Node(int _x, int _y) : x(_x), y(_y){};
}; 
int bfs(int x, int y, vector<vector<bool>>& vis){
	int cnt = 0, level=1, sum=0;
	queue<Node>q;
	q.push(Node(x,y));
	vis[x][y]=true;
	if(a[x][y]>0){
		cnt++;
	}
	while(!q.empty()){
		int len = q.size();
		while(len--){
			Node cur = q.front();
//			cout<<"cur x:"<<cur.x<<" y:"<<cur.y<<endl;
			q.pop();
			for(int i=0;i<8;i++){
				int dx = cur.x+step[i][0];
				int dy =cur.y+step[i][1];
//				cout<<"dx:"<<dx<<" dy:"<<dy<<endl;
				if(dx>=1&&dy>=1&&dx<=n&&dy<=m){//不是边界
					if(!vis[dx][dy]&&a[dx][dy]>=0){//没访问过的落点，且 //&&a[dx][dy]>=level&&a[dx][dy]>0
						q.push(Node(dx,dy));
						if(a[dx][dy]>=level){//且步数够用 ,为马
							cnt++;
							sum+=level;//记录步数 
						}
					}
					vis[dx][dy]=true;
				}

			}
		}
		if(cnt==sumM){
			return sum;
		}
		level++;
	}
	return -1;//没照全 
}
int main(){
	cin>>n>>m;
	memset(a, -1, sizeof(a));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			string s;
			cin>>s;
			if(s=="."){
				a[i][j]=0;
			}
			else{
				a[i][j] = stoi(s);
				sumM++;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<a[i][j]<<' ';
//		}cout<<endl;
//	}
	if(sumM==1){//特判只有一个马 
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));//小心vis得多一圈 
//			cout<<"bfs i:"<<i<<" j:"<<j<<endl;
			int sum = bfs(i,j,vis);
//			cout<<"sum:"<<sum<<endl;
			if(sum>0){
				ans = min(ans, sum);
			} 
		}
	}
	if(ans!=notFind){
		cout<<ans<<endl;
	}
	else{
		cout<<0<<endl;
	}
}
/*
3 3
2 . 2
. . .
. . .

3 2
. .
2 .
. .

3 5
4 7 . 4 8
4 7 4 4 .
7 . . . .

*/
