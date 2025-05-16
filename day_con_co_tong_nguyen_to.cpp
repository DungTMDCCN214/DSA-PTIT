#include<bits/stdc++.h>

using namespace std;

int k;
int a[100];
vector<int> v;
set<vector<int>> ans;
int check(int z){
	for (int i = 2; i <= sqrt(z);i++){
		if(z%i==0)
			return 0;
	}
	return z > 1;
}

void Try(int pre, int sum){
	for (int i = pre + 1; i <= k;i++){
		v.push_back(a[i]);
		if(check(sum+a[i])){
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
		for (int i = 1; i <= k;i++){
			cin >> a[i];
		}
		ans.clear();
		sort(a + 1, a + k + 1, greater<int>());
		Try(0, 0);
		for(auto x:ans){
			for(auto e:x){
				cout << e << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

