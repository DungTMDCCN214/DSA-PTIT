#include<bits/stdc++.h>

using namespace std;

// Hoan vi ca day so;
string s[9];
int n, k, a[9];
int check(){
	int ma = -1e9, mi = 1e9;
	for (int i = 0; i < n;i++){
		int num = 0;
		for (int j = 0; j < k;j++){
			num += (s[i][a[j]] - '0') * pow(10, k - j - 1);
		}
		ma = max(ma, num);
		mi = min(mi, num);
	}
	return ma - mi;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n;i++){
		cin >> s[i];
	}
	for (int i = 0; i < k;i++){
		a[i] = i;
	}
	int ans = 1e9;
	do
		ans = min(ans, check());
	while (next_permutation(a, a + k));
	cout << ans;
	return 0;
}

