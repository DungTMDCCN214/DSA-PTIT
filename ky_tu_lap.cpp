#include<bits/stdc++.h>

using namespace std;
string a[100];
int n;
int minx=1e9;
int x[100];
bool used[100];

int dem(int i){
	if(i==1)
		return 0;
	string tmp1 = a[x[i - 1]], tmp2 = a[x[i]];
	// Là i-1 mà ko phai i+1 là do để so sánh cái hiện tại với cái trước đó;
	i = 0;
	int j = 0, cnt = 0;
	while(i<tmp1.size() && j<tmp2.size()){
		if(tmp1[i]==tmp2[j]){
			i++;
			j++;
			cnt++;
		} else if(tmp1[i]<tmp2[j]){
			i++;
		} else
			j++;
	}
	return cnt;
}

// Su dung hoan vi dem cac truong hop

void Try(int i, int cnt){
	for (int j = 1; j <= n;j++){
		if(used[j]==false){
			x[i] = j;
			used[j] = true;
			int tmp = dem(i);
			if(i==n) {
				minx = min(minx, cnt + tmp);
			} else {
				Try(i + 1, cnt + tmp);
			}
			used[j] = false;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n;i++){
		cin >> a[i];
	}
	Try(1, 0);
	cout << minx;
	return 0;
}

