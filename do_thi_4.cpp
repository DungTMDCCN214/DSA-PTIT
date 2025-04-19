#include<bits/stdc++.h>

using namespace std;
ifstream fin("DT.INP");
ofstream fout("DT.OUT");
int main() {
	int t;
	fin>>t;
	int n,m;
	fin>>n>>m;
	int a[n+1]={0};
	int b[n+1][n+1]={0};
	int k=m;
	while(k--){
		int x,y;
		fin>>x>>y;
		a[x]++;
		a[y]++;
		b[x][y]=1;
		b[y][x]=1;
	}
	if(t==1){
		for(int i=0;i<n;i++){
			fout<<a[i+1]<<" ";
		}
	} else if(t==2){
		fout<<n<<endl;
		for(int i=0;i<n;i++){

			for(int j=0;j<n;j++){
				fout<<b[i+1][j+1]<<" ";
			}
			fout<<endl;
		}
	}
	return 0;
}

