#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<int> a;
		a.push(-1);
		int tmp = -1;
		for (int i = 0;i<s.size();i++){
			if(s[i]=='('){
				a.push(i);
			} else {
				a.pop();
				if(a.empty())
					a.push(i);
				else {
					tmp = max(tmp, i - a.top());
				}
			}
		}
		cout << tmp << endl;
	}
	return 0;
}

