#include<bits/stdc++.h>

using namespace std;

int n, p, s;

vector<int> x;

int check(int k){
	for (int i = 2; i <= sqrt(k);i++){
		if(k%i==0)
			return 0;
	}
	return k>1;
}
int a[11];
void init(){
	x.clear();
	for (int i = 2; i <= 200;i++){
		if(check(i)){
			x.push_back(i);
		}
	}
}
vector<string> ans;
void add(){
	string m = "";
	for(int i = 1; i <= n;i++){
		m += to_string(a[i]) + " ";
	}
	ans.push_back(m);
}
void Try(int k, int t, int sum){
	for (int j = t + 1; j < x.size();j++){
		if(x[j]<=p)
			continue;
		if(sum+x[j]>s)
			continue;
		a[k] = x[j];
		if(k==n && sum+x[j]==s){
			add();
		}
		if(k<n)
			Try(k + 1, j, sum+x[j]);
	}
}
int main() {
	init();
	int t;
	cin >> t;
	while(t--){
		cin >> n >> p >> s;
		ans.clear();
		Try(1, 0, 0);
		sort(ans.begin(), ans.end());

		cout << ans.size()<<endl;
		for(auto z:ans){
			cout << z << endl;
		}
	}
	return 0;
}

