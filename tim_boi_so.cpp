#include<bits/stdc++.h>

using namespace std;
long long check(int n){
	queue<long long> res;
	long long start = 9;
	res.push(start);
	while(!res.empty()){
		long long tmp = res.front();
		res.pop();
		if(tmp%n==0){
			return tmp;
		} else {
			res.push(tmp * 10);
			res.push(tmp * 10 + 9);
		}
	}
	return -1;
}
int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout<<check(n);
		cout << endl;
	}
	return 0;
}

