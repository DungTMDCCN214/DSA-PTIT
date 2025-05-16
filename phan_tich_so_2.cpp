#include<bits/stdc++.h>

using namespace std;
int n;
int  a[100];
vector<string> v;
void in(int k){
	string s = "";
	s += "(";
	for (int i = 0; i < k;i++){
		s += to_string(a[i]);
		if(i!=k-1){
			s += " ";
		}
	}
	s += ")";
	v.push_back(s);
}

void Try(int i, int pre,int sum){
	for (int j = pre; j >= 1;j--){
		if(sum+j>n)
			continue;
		a[i] = j;
		if(sum+j==n){
			in(i + 1);
		} else {
			Try(i + 1, j, sum + j);
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		v.clear();
		Try(0, n, 0);
		cout << v.size() << endl;
		for(auto x:v){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}

