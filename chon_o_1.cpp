#include<bits/stdc++.h>

using namespace std;
/*
a<<b phep dich bit a (trong he nhi phan) sang trai b lan;
1<<0 : 001 ~ 2^0
1<<1 : 010 ~ 2^1
1<<2 : 100 ~ 2^2

-> 1<<b ~ 2^b
*/
int a[21][21], dp[21][1<<21],n;

int tryAt(int i, int pre){
	if(i > n) return 0;
	if(dp[i][pre] !=-1) return dp[i][pre];
	int rowStatus = 1<<(n-1);
	int ma=0;
	for(int j=1;j<=n;j++){
		if((pre & rowStatus)==0){
			int current = pre|rowStatus;
			ma=max(ma,a[i][j]+tryAt(i+1, current));
		}
		rowStatus = rowStatus>>1;
	}
	dp[i][pre]= ma;
	return ma;
} 
int main() {
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		memset(dp,-1,sizeof dp);
		cout<<tryAt(1,0)<<endl;
	}
	return 0;
}

