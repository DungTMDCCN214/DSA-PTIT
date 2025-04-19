#include<bits/stdc++.h>

using namespace std;
ifstream fin("DT.INP");
ofstream fout("DT.OUT");
int main() {	
	int t;
	fin>>t;
	int n;
	fin>>n;
	int b[105]={0};
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fin>>a[i][j];
			if(a[i][j]==1) b[i]++;
		}
	}
	if(t==1){
		for(int i=0;i<n;i++){
			fout<<b[i]<<" ";
		}
	} else {
		fout<<n<<" ";
		int k = 0;
		for (int i = 0; i < n;i++){
			for (int j = i; j < n;j++){
				if(a[i][j]==1){
					k++;
				}
			}
		}
		fout << k << endl;
		for (int i = 0; i < n; i++){
			for (int j = i+1; j < n;j++){
				if(a[i][j]==1){
					fout << i + 1 << " " << j + 1 << endl;
				}
			}
		}
	}
	fin.close();
	fout.close();
	return 0;	
}

