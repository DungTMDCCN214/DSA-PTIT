#include<bits/stdc++.h>

using namespace std;
int dem=1e9;
void Try( int cnt, int n){
	if(cnt>dem){
		return;
	}
	if(n==1)
		dem = min(cnt, dem);
	if(n%2==0){
		Try(cnt + 1, n / 2);
	}
	if(n%3==0){
		Try(cnt + 1, n / 3);
	}
	if(n!=1) {
		Try(cnt + 1, n - 1);
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		dem = 1e9;
		int n;
		cin >> n;
		Try(0, n);
		cout << dem << endl;
	}
	return 0;
}

