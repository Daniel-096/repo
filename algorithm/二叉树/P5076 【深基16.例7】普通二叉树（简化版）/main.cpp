#include<bits/stdc++.h>
using namespace std;
int n;
set<int>s;//why?�ظ�x�� 
int main(){
	cin>>n;
	s.insert(-0x7fffffff);
	s.insert(0x7fffffff);
	while(n--){
		int op,num;
		cin>>op>>num;
		if(op==1){
			auto p = s.lower_bound(num);//����num���Ͻ�
			int cnt = 0;//ȥͷ 
			while(p!=s.begin()){
				p--;
				cnt++;
			} 
			cout<<cnt<<endl;
			
		}
		else if(op==2){//��xλ 
			int cnt = 0;//ȥͷ 
			for(auto p=s.begin();p!=s.end();p++){
				if(cnt==num){
					cout<<*p<<endl;
					break;
				}
				cnt++;
			}
		}
		else if(op==3){
			auto p = s.lower_bound(num);
			p--;
			cout<<*p<<endl;
		}
		else if(op==4){
			auto p = s.upper_bound(num);
			cout<<*p<<endl;
		}
		else{
			s.insert(num);
		}
	}
}
/*
7
5 1
5 3
5 5
1 3
2 2
3 3
4 3
//x���� 
7
5 1
5 3
5 5
1 4
2 2
3 3
4 3

7
5 1
5 3
5 5
1 2
2 2
3 3
4 3
//ǰ����
7
5 1
5 3
5 5
1 1
2 2
3 1
4 5 

7
5 1
5 3
5 5
1 3
2 1
3 3
4 3

7
5 1
5 1
5 5
1 3
2 2
3 3
4 3
*/ 
