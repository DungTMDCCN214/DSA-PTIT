#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[501][501];

int di[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dj[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void tryAt(int i, int j){
	if(i<0 || i==n || j<0 || j==m){
		return;
	}
	if(a[i][j]==0)
		return;
	a[i][j] = 0;
	for (int k = 0; k < 8;k++){
		tryAt(i + di[k], j + dj[k]);
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for (int i = 0; i < n;i++){
			for (int j = 0; j < m;j++){
				cin >> a[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < n;i++){
			for (int j = 0; j < m;j++){
				if(a[i][j]==1) {
					cnt++;
					tryAt(i, j);
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

