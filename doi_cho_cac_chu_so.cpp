#include<bits/stdc++.h>

using namespace std;

string s,ans;
void tryAt (int i, int k){
	if(k==0 || i==s.size())
		return;
	char ma = *max_element(s.begin() + i, s.end());
	if(ma==s[i])
		tryAt(i + 1, k);
	for (int j = i + 1; j < s.size() ;j++){
		if(s[j]!=ma)
			continue; // Neu ko phai lon nhat thi bo qua tat ca lenh dang sau va for tiep
			swap(s[i], s[j]);
		if(ans<s)
			ans = s;
		if(i<s.size()-1)
			tryAt(i + 1, k - 1);
		swap(s[i], s[j]); // Khoi phuc trang thai;
	}
}
int main() {
	int t;
	cin>>t;
	while(t--){
		int k;
		cin >> k>>s;
		ans = s;
		tryAt(0, k);
		cout << ans << endl;
	}
	return 0;
}

