#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int k=n-1;
		while(k>=1 && a[k]>a[k+1]){
			k--;
		}
		if(k==0){
			for(int i=1;i<=n;i++){
				cout<<i<<" ";
			}
		} else {
			int j=n;
			while(a[k]>a[j]) j--;
			swap(a[k],a[j]);
			int l=k+1, r=n;
			while(l<r){
				swap(a[l],a[r]);
				l++;
				r--;
			}
			for(int i=1;i<=n;i++){
				cout<<a[i]<<" ";
			}
		}
		cout<<endl;
	} 
	return 0;
}

