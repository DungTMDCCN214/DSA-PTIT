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
		int b[n], ans=-1;
		b[n-1]=a[n-1];
		for(int i=n-2;i>=0;i--){
			b[i]=max(b[i+1],a[i]);
		}
		int i,j;
		i=0,j=0;
		while(i<n && j<n){
			if(b[j]>a[i]){
				ans=max(ans,j-i);
				j++;
			} else i++;
		}
		if(!ans) ans=-1;
		cout<<ans<<endl;
	}
	return 0;
}

