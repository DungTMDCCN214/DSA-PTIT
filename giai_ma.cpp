#include<bits/stdc++.h>

using namespace std;


int check(string a){
	int n=a.size();
	if(n==0 || a[0]=='0') return 0;
	vector<int> dp(n+1,0);
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		if(dp[i-1]!='0'){
			dp[i]+=dp[i-1];
		}
		int k=stoi(a.substr(i-2,2));
		if(k>=10 && k<=26){
			dp[i]+=dp[i-2];
		}
	}
	return dp[n];
	
}
int main() {
	int t;
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		cout<<check(a)<<endl;
	} 
	return 0;
}


/*
Quy ho?ch �?ng (DP)
B�?c c� s?:

dp[0] = 1 (chu?i r?ng c� m?t c�ch gi?i m?).

dp[1] = 1 n?u M[0] ? '0', ng�?c l?i th? kh�ng c� c�ch gi?i m? h?p l? (dp[1] = 0).

C�ng th?c truy h?i:

dp[i] += dp[i-1] n?u M[i-1] ? '0'

dp[i] += dp[i-2] n?u 10 ? stoi(M[i-2]M[i-1]) ? 26

*/
