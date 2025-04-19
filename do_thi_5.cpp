#include<bits/stdc++.h>

using namespace std;

ifstream fin("DT.INP");
ofstream fout("DT.OUT");
int main() {
	int t;
	fin >> t;
	int n, m;
	fin >> n >> m;
	int a[n + 1] = {0};
	int b[n + 1][n + 1] = {0};
	int k = m;
	while(k--){
		int x, y;
		fin >> x >> y;
		a[x]++;
		a[y]++;
		b[x][y] = 1;
		b[y][x] = 1;
	}
	if(t==1){
		for (int i = 1; i <= n;i++){
			fout << a[i] << " ";
		}
	} else {
		fout << n << endl;
		for (int i = 1; i <= n;i++){
			fout << a[i] << " ";
			for (int j = 1; j <= n;j++){
				if(b[i][j]==1){
					fout << j << " ";
				}
			}
			fout << endl;
		}
	}
	return 0;
}

