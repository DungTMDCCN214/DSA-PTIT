#include<bits/stdc++.h>

using namespace std;

#define ll long long
int mod=1e9+7;
map<ll,ll> f;
ll fibo(long long n){
	if(f[n]!=0) return f[n];
	ll k=n/2;
	if(n%2==1 ) return f[n]=(fibo(k)*fibo(k+1) + fibo(k-1)*fibo(k))%mod;
	return f[n]=(fibo(k)*fibo(k) + fibo(k-1)*fibo(k-1))%mod;
}
int main() {
	int t,n;
	cin>>t;
	f[0]=f[1]=1;
	while(t--){
		cin>>n;
		if(n==0) cout<<"0"<<endl;
		else cout<<fibo(n-1)<<endl;
	}
	return 0;
}

