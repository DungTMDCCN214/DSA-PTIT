#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		long  long a[n];
		for(long long  i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		long long ans=0;
		for(long long i=n-1;i>=0;i--){
			long long *it=upper_bound(a,a+i,a[i]-k);
			ans+=a+i-it;
		}
		cout<<ans<<endl;
	}
	return 0;
}

