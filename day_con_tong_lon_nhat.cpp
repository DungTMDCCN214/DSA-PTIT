#include<bits/stdc++.h>

using namespace std;

const int z=100005;
int a[z];
int check(int l, int r){
	int max1=0, k=0;
	for(int i=l;i<=r;i++){
		k=max(0,k+a[i]);
		max1=max(max1,max1+k);
	}
	return max1;
} 
int main() {
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l,r;
	while(q--){
		cin>>l>>r;
		cout<<check(l,r)<<endl;
	}
	return 0;
}

