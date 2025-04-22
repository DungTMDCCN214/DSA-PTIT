#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
		int check = 0;
		int n, k;
		cin >> n >> k;
		int b[n + 1] = {};
		int a[k + 1];
		for (int i = 1; i <= k;i++){
			cin >> a[i];
			b[a[i]]++;
		}
		int x = k;
		while (x >= 1 && a[x]==n-k+x){
			x--;
		}
		if(x>=1){
			a[x] = a[x] + 1;
			for (int j = x + 1; j <= k;j++){
				a[j] = a[x] + j - x;
			}
			for (int i = 1; i <= k;i++){
				b[a[i]]++;
			}
		} else
			check = 1;
		if(check ==1){
			cout << k << endl;
		} else {
			int cnt = 0;
			for (int i = 1; i <= n;i++){
				if(b[i]==2)
					cnt++;
			}
			cout << k-cnt << endl;
		}
	}
	return 0;
}

