#include<bits/stdc++.h>

using namespace std;

int n, k;
int a[100];
vector<int> v;
set<vector<int>> ans;
int check(){
	for (int i = 1; i < v.size();i++){
		if(v[i]<=v[i-1])
			return 0;
	}
	return 1;
}

void Try(int pre, int m){
			if(m==k){
			if(check()){
				ans.insert(v);
			}
		}
	for (int i = pre + 1; i <= n;i++){
		v.push_back(a[i]);
		Try(i, m + 1);
		v.pop_back();
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
		ans.clear();
		v.clear();
		sort(a + 1, a + n + 1);
		Try(0, 0);
		for(auto x:ans){
			for(auto z:x){
				cout << z << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

