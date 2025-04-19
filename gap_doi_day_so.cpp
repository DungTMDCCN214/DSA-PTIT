#include<bits/stdc++.h>

using namespace std;

#define ll long long
ll mu(ll a, ll b){
	if(b==0) return 1;
	ll res=mu(a,b/2);
	if(b%2==1) return res*res*2;
	else return res*res;
}

ll gapdoi(ll n, ll k){
	ll x=mu(2,n-1);
	if(k==x) return n;
	if(k<x){
		return gapdoi(n-1,k);
	}
	return gapdoi(n-1,k-x);
}
int main() {
	int t;
	cin>>t;
	while(t--){
		long long a,b;
		cin>>a>>b;
		cout<<gapdoi(a,b)<<endl;
	} 
	return 0;
}

