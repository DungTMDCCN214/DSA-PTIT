#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,k,x;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		next_permutation(a.begin(), a.end());
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	} 
	return 0;
}

