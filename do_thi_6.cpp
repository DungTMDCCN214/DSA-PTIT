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
	int b[n + 1][m + 1] = {0};
	int z = 1;
	int l = m;
	while(l--){
		int x, y;
		fin >> x >> y;
		a[x]++;
		a[y]++;
		b[x][z] = 1;
		b[y][z] = 1;
		z++;
	}
	if(t==1){
		for (int i = 1; i <= n;i++){
			fout << a[i] << " ";
		}
	} else {
		fout << n <<" "<< m<<endl;
		for (int i = 1; i <= n;i++){
			for (int j = 1; j <= m;j++){
				fout << b[i][j] << " ";
			}
			fout << endl;
		}
	}
	return 0;
}

