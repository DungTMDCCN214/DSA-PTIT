#include<bits/stdc++.h>

using namespace std;

int res, k, n;
int a[30][30];
int x[30];
bool ok[30];
vector<int> Res;

void Try(int i){
	for (int j = 1; j <= n;j++){
		if(!ok[j]){
			x[i] = j;
			ok[j] = true;
			if(i==n){
				res = 0;
				for (int l = 1; l <= n;l++){
					res += a[l][x[l]];
				}
				if(res==k){
					for (int l = 1; l <= n;l++){
						Res.push_back(x[l]);
					}
				}
			}
			else
				Try(i + 1);
			ok[j] = false;
		}
	}
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n;i++){
		for (int j = 1; j <= n;j++){
			cin >> a[i][j];
		}
	}
	Try(1);
	cout << Res.size() / n;
	for (int i = 0; i < Res.size();i++){
		if(i%n==0)
			cout << endl;
		cout << Res[i] << " ";
	}
		return 0;
}

