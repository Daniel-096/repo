#include<bits/stdc++.h>//11点前不算熬夜 
using namespace std;
int n;
int a[305][305];
bool vis[305][305];
int step[5][2] = {{1, 0}, {-1, 0}, {0,1},{0,-1},{0,0}};//5步，含自己 
struct Node{
	int x;
	int y;
};
int main(){//dfs
	cin>>n;
	memset(a,-1,sizeof(a));
	memset(vis, false ,sizeof(vis));
	for(int i=0;i<n;i++){//下标为0 
		int x,y,t;
		cin>>x>>y;
		cin>>t;//这里有bug，也要判早晚 
		for(int j=0;j<5;j++){
			int x1 = x+step[j][0];
			int y1 = y+step[j][1];
			if(x1>=0&&y1>=0){
				a[x1][y1] = a[x1][y1]==-1?t : min(t, a[x1][y1]);//小心覆盖 
			}
		}
	}
	
	//特判起点被哄或安全 
	if(a[0][0]==0){
		cout<<"-1";
		return 0;
	}
	else if(a[0][0]==-1){
		cout<<"0";
		return 0;
	}
	vis[0][0] = true;//处理边界 
	queue<Node>q;
	Node tmp;
	tmp.x = 0, tmp.y =0;
	q.push(tmp);
	int level = 1;
	while(!q.empty()){//分层 
		int cnt = q.size();
		while(cnt--){
			Node cur = q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int x1 = step[i][0]+cur.x;
				int y1 = step[i][1]+cur.y;
				if(x1>=0&&y1>=0&&!vis[x1][y1]){//没越界，没超时，没访问 
					if(a[x1][y1]==-1){
						cout<<level;
						return 0;
					}
					else if(level<a[x1][y1]){
						vis[x1][y1] = true;
						tmp.x = x1;
						tmp.y = y1;
						q.push(tmp);
					}

				}
			} 
		}
		level++;
	}
	cout<<"-1"<<endl;

	
} 
/*
4
0 0 2
2 1 2
1 1 2
0 3 5

4
0 0 2
2 1 2
1 1 2
1 2 5


4
0 0 0
2 1 2
1 1 2
1 2 5

-1

3
2 1 2
1 1 2
1 2 5

4
0 0 1
2 1 2
1 1 2
1 2 5

3
0 0 3
0 0 4
0 0 5
*/
