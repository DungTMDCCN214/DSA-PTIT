#include<bits/stdc++.h>

using namespace std;


bool kt(long long a[], int n,int k){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(binary_search(a+j+1,a+n,k-a[i]-a[j])) return true;
		}
	}
	return false;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		long long a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		if(kt(a,n,k)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

