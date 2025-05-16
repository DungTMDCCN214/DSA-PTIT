#include<bits/stdc++.h>

using namespace std;
int n;
string s;
vector<string> ans;
string res; 

void Try(int i){
	for (int j = i; j <= n;j++){
		res.push_back(s[j]);
		if(!res.empty()){
			ans.push_back(res);
		}
		Try(j + 1);
		res.pop_back();
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		cin >> s;
		s = " "+s;
		ans.clear();
		Try(1);
		sort(ans.begin(), ans.end());
		for(auto x:ans){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}

