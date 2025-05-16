#include<bits/stdc++.h>

using namespace std;
int k;
int a[100];
set<vector<int>> ans;
vector<int> v;
// Liet ke theo thu tu tu dien tang dan khong duoc dung string, phai dung vector<int>;
void Try(int pre, int sum){
	for (int i = pre + 1; i <= k;i++){
		v.push_back(a[i]);
		if((sum+a[i])%2==1){
			ans.insert(v);
		}
		Try(i, sum + a[i]);
		v.pop_back();
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> k;
		ans.clear();
		for (int i = 1; i <= k;i++){
			cin >> a[i];
		}
		sort(a+1, a + k+1, greater<int>());
		Try(0, 0);
		for(auto x:ans){
			for(auto z:x){
				cout << z<<" ";
			}
			cout << endl;
		}
	}
	return 0;
}

