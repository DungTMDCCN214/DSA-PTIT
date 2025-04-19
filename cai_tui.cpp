#include<bits/stdc++.h>

using namespace std;

int main() {
	int x;
	cin>>x;
	while(x--){
		int n,v;
		cin>>n>>v;
		int a[n+1], b[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		int dp[n+1][v+1];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=v;j++){
				dp[i][j]=dp[i-1][j];
				if(j>=a[i]){
					dp[i][j]=max(dp[i][j], dp[i-1][j-a[i]]+b[i]);
				}
			}
		}
		cout<<dp[n][v]<<endl;
	}
	return 0;
}

