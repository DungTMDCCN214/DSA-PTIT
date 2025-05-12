#include<bits/stdc++.h>

using namespace std;
int n, k;
int a[1001], x[1001];
bool ok = true;
void print(int z){
	ok = false;
	cout << "[";
	for (int i = 1; i < z;i++){
		cout << x[i] << " ";
	}
	cout <<x[z]<< "]";
}
void Try(int i, int cnt, int sum){
	for (int j = cnt; j <= n;j++){
		if(sum+a[j]>k)
			continue;
		x[i] = a[j];
		if(sum+a[j]==k)
			print(i);
			else
				Try(i + 1, j, sum + a[j]);
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for (int i = 1; i <= n;i++){
			cin >> a[i];
		}
		Try(1,1  , 0);
		if(ok==true)
			cout << "-1";
		cout << endl;
	}
	return 0;
}

