#include<bits/stdc++.h>

using namespace std;

// Cac dinh bac chan 
// Neu co dinh bac le thi co 2 dinh , bat dau tai 1 dinh va ket thuc tai dinh con lai


int main() {
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int u, v;
		int a[1001]= {};
		while(m--){
			cin >> u >> v;
			a[u]++;
			a[v]++;
		}
		int cnt = 0;
		for (int i = 1; i <= n;i++){
			cnt += a[i] % 2;
		}
		if(cnt==0)
			cout << 2 << endl;
		else if(cnt==2){
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}
