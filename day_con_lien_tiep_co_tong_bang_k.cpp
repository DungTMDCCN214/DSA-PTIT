#include<bits/stdc++.h>

using namespace std;

int kt(long long a[], int n, long long k){
	map<long long, int> m;
	long long sum = 0;
	for (int i = 0; i < n;i++){
		sum += a[i];
		if(sum==k || m[sum-k]==1)
			return 1;
		m[sum] = 1;
	}
	return 0;
}
int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		long long k;
		cin >> n >> k;
		long long a[n];
		for (int i = 0; i < n;i++){
			cin >> a[i];
		}
		if(kt(a, n, k)){
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}

