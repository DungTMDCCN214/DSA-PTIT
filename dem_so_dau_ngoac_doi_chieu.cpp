#include<bits/stdc++.h>

using namespace std;

int check(string s){
	stack<char> st;
	int cnt1=0, cnt2=0;
	for(char i:s){
		if(i==')' && st.size()>0 && st.top()=='(') st.pop();
		else st.push(i);
	}
	while(st.size()){
		if(st.top()=='(') cnt1++;
		else cnt2++;
		st.pop();
	}
	return int(cnt1/2) + int(cnt2/2) + (cnt1%2) + (cnt2%2);
}
int main() {
	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		cout<<check(s)<<endl;
	}
	return 0;
}

