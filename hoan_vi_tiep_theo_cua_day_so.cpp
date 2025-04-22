#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		string s;
		cin >> s;
		int i = s.length() - 1, j = s.length() - 1;
		while(s[i]<=s[i-1] && i>0){
			i--;
		}
		i--;
		if(i<0){
			cout << k << " BIGGEST" << endl;
		} else {
			while(s[j]<=s[i]){
				j--;
			}
			swap(s[j], s[i]);
			sort(s.begin() + i + 1, s.end());
			cout << k << " " ;
			for (int i = 0; i < s.length();i++){
				cout << s[i];
			}
			cout << endl;
		}
	}
	return 0;
}

