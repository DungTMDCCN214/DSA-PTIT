#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		int k=1e9;
		for(int i=1;i<n;i++){
			k=min(k,abs(a[i]-a[i-1]));
		}
		cout<<k<<endl;
	} 
	return 0;
}

