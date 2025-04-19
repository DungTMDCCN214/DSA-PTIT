#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		long long sum=0,res=0;
		for(int i=0;i<n;i++){
			if(i<k){
				sum-=a[i];
			} else {
				sum+=a[i];
			}
			if(i<n-k){
				res-=a[i];
			} else {
				res+=a[i];
			}
		}
		cout<<max(res,sum)<<endl;
	}
	return 0;
}

