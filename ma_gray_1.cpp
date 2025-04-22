#include<bits/stdc++.h>

using namespace std;

// Ham doi xung
// Them 0,1
// duyet tu cuoi len den dau thi push vao den do va them 0+ans[j];
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin >> n;
		vector<string> ans;
		ans.push_back("0");
		ans.push_back("1");
		for (int i = 2; i <= n;i++){
			for (int j = ans.size()-1; j >= 0;j--){
				ans.push_back("1" + ans[j]);
				ans[j] = "0" + ans[j];
			}
		}
		for(auto x:ans){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}

