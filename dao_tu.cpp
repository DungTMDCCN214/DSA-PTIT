#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string a;
		getline(cin, a);
		stack<string> b;
		stringstream s(a);
		string c;
		while(s>>c){
			b.push(c);
		}
		while(!b.empty()){
			cout << b.top() << " ";
			b.pop();
		}
		cout << endl;
	}
	return 0;
}

