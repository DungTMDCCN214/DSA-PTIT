#include<bits/stdc++.h>

using namespace std;
int a[9][9];
int c[9], c1[18], c2[18];
int ans;

void Try(int i, int score){
	for (int j = 1; j <= 8;j++){
		if(c[j]==1 || c1[i-j+8]==1 || c2[i+j-1]==1){
			
			continue;
		}
		c[j] = c1[i - j + 8] = c2[i + j - 1] = 1;
		if(i==8 && score+a[i][j]>ans){
			ans = score + a[i][j];
		}
		if(i<8){
			Try(i + 1, score + a[i][j]);
		}
		c[j] = c1[i - j + 8] = c2[i + j - 1] = 0;
	}
}

int main() {
	int t;
	cin >> t;
	int k = 1;
	while(t--){
		for (int i = 1; i <= 8;i++){
			for (int j = 1; j <= 8;j++){
				cin >> a[i][j];
			}
		}
		memset(c, 0, sizeof(c));
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		ans = 0;
		Try(1, 0);
		cout << "Test " << k << ": ";
		k++;
		cout << ans << endl;

	}
}

// 2n-1 cot cheo;
