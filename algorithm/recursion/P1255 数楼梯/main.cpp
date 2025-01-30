#include<bits/stdc++.h>
using namespace std;
int n;
string dp[5005];
string add(string & s1, string & s2){
	string ans = "";
	int n1 = s1.size()-1;//表示下标范围； 
	int n2 = s2.size()-1;
	int carry = 0;//当一方过短而取不到值时，短方x取0 ；长度为下标长度 
	while(carry||n1>=0||n2>=0){//要取到等于0？ 因为下标最小为0 
		int x1 = n1>=0?s1[n1]-'0':0;//循环条件一方长度不为0或者有进位时 
		int x2 = n2>=0?s2[n2]-'0':0;
		int val = (carry+x1+x2)%10;
		carry = (carry+x1+x2)/10;
		ans+=to_string(val);
		n1--;//别忘了推进长度 
		n2--;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int main(){
	cin>>n;
	dp[1] = "1",dp[2]="2";
	for(int i=3;i<=n;i++){
		dp[i] = add(dp[i-1], dp[i-2]);
	}
	cout<<dp[n]<<endl;
} 
