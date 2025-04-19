#include<bits/stdc++.h>

using namespace std;

// Cac dinh co dau ra bang dau vao

int main() {
	int t;
	cin >> t;
	int v, e;
	while(t--){
		cin >> v >> e;
		int a[v+1] = {};
		int b[v + 1] = {};
		int x, y;
		while(e--){
			cin >> x >> y;
			a[x]++;
			b[y]++;
		}
		int cnt = 0;
		int ok = 1;
		for (int i = 1; i <= v;i++){
			if(a[i]!=b[i]){
				ok = 0;
				break;
			}
		}
		cout << ok<<endl;
	}
	return 0;
}

