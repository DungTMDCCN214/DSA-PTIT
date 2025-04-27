#include<bits/stdc++.h>

using namespace std;

int n, maxx;
int val[100];
int x[100], wei[100];
int xopt[100];
int fopt = INT_MIN;
void caitui(){
	int xich_ma = 0, w = 0;
	for (int i = 1; i <= n;i++){
		xich_ma += val[i]*x[i];
		w += wei[i] * x[i];
	}
	if(w<=maxx && xich_ma>=fopt){
		fopt = xich_ma;
		for (int i = 1; i <= n;i++){
			xopt[i] = x[i];
		}
	}
}
void Try(int index){
	for (int i = 0; i <= 1;i++){
		x[index] = i;
		if(index==n)
			caitui();
			else
				Try(index + 1);
	}
}
int main() {
	cin >> n >> maxx;
	for (int i = 1; i <= n;i++){
		cin >> val[i];
	}
	for (int i = 1; i <= n;i++){
		cin >> wei[i];
	}
	Try(1);
	cout << fopt << endl;
	for (int i = 1; i <= n;i++){
		cout << xopt[i] << " ";
	}
		return 0;
}

