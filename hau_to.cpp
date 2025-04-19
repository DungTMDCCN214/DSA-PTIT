#include<bits/stdc++.h>

using namespace std;
long long doi(string s){
	long long c = 0;
	int start = 0;
	int sign = 1;
	int tmp = 0;
	if(s[0]=='-'){
		sign = -1;
		start = 1;
	}
	for (int i = s.size() - 1; i >= start; i--)
	{
		c = (s[i] - '0') * pow(10,tmp) + c;
		tmp++;
	}
	return c * sign;
}
int main() {
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		stack<long long> st;
		while(x--){
			string a;
			cin >> a;
			long long z;
			if(a=="+" || a=="-" || a=="*" || a=="/" || a=="%" || a=="^"){
				long long m = st.top();
				st.pop();
				long long n = st.top();
				st.pop();
				if(a=="+"){
					z = n + m;
				} else if(a=="-"){
					z = n - m;
				} else if(a=="*"){
					z = n * m;
				} else if(a=="/"){
					z = n / m;
				} else if(a=="%"){
					z = n % m;
				} else if(a=="^"){
					z = 1;
					for (int i = 0;i<m;i++){
						z *= n;
					}
				}
				st.push(z);
			} else {
				st.push(doi(a));
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}

