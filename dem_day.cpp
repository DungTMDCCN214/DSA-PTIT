#include<bits/stdc++.h>

using namespace std;

#define MOD 123456789
#define ll long long 
ll demday(ll n){
	if(n==1) return 1;
	ll x=demday(n/2)%MOD;
	if(n%2==1) return ((x*x%MOD)*4)%MOD;
	else return ((x*x%MOD)*2)%MOD;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		cout<<demday(n)<<endl;
	}
	return 0;
}

