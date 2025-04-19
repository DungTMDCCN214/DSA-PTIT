#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n][n]; 
		for(int i=1;i<=n;i++){
			cin>>a[1][i];
		}
		int cot=n-1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=cot;j++){
				a[i][j]=a[i-1][j]+a[i-1][j+1];
			}
			cot--;
		}
		cot=1;
		for(int i=n;i>=1;i--){
			cout<<"[";
			for(int j=1;j<=cot;j++){
				if(j==cot) cout<<a[i][j];
				else cout<<a[i][j]<<" ";
			}
			cout<<"]";
			cout<<" ";
			cot++;
		}
		cout<<endl;
	}
	return 0;
}

