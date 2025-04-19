#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a;
		map<int,int> mp;
		long long cnt=0;
		while(n--){
			cin>>a;
			cnt+=mp[k-a];
			mp[a]++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}

