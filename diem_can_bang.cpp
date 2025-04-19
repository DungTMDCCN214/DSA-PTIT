#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		int ok=0;
		int l=0,r=sum;
		for(int i=1;i<=n;i++){
			r-=a[i];
			if(l==r) {
				cout<<i<<endl;
				ok=1;
				break;
			} else {
				l+=a[i];
			}
		}
		if(ok==0) cout<<"-1"<<endl;
	}
	return 0;
}

