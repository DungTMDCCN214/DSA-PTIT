#include<bits/stdc++.h>

using namespace std;




int n, k;
int a[1001], x[1001];
vector<string> c;
bool ok = true;

void print(int z){
	ok = false;
	string b = "";
	for (int i = 1; i <= z;i++){
		b += to_string(x[i]);
		if(i!=z){
			b += " ";
		}
	}
	c.push_back(b);
}

void Try(int i, int cnt, int sum){
	for (int j = cnt; j <= n;j++){
		if(sum+a[j]>k)
			continue;
		x[i] = a[j];
		if(sum+a[j]==k){
			print(i);
		} else {
			Try(i + 1, j, sum + a[j]);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--){
		c.clear();
		ok = true;
		cin >> n >> k;
		for (int i = 1; i <= n;i++){
			cin >> a[i];
		}
		sort(a+1, a + n+1);
		Try(1, 1, 0);
		if (ok == true)
			cout << "-1" << endl;
		else {
			cout << c.size()<<" ";
			for(auto m:c){
				cout << "{" << m << "}" << " ";
			}
			cout << endl;
		}
	}
}
