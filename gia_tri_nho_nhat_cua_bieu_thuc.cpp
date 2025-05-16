#include<bits/stdc++.h>

using namespace std;
int n;
long long check(long long a[], long long b[]){
	long long sum = 0;
	for (int i = 1; i <= n;i++){
		sum += (a[i] * b[i]);
	}
	return sum;
}
int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		long long a[n + 1];
		long long b[n + 1];
		for (int i = 1; i <= n;i++){
			cin >> a[i];
		}
		for (int i = 1; i <= n;i++){
			cin >> b[i];
		}
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n, greater<int>());
		cout << min(check(a, b), check(b, a))<<endl;
	}
	return 0;
}

