#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<string> stk;
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='%' || s[i]=='^'){
				string fi=stk.top();
				stk.pop();
				string se=stk.top();
				stk.pop();
				string tmp="(" + fi+s[i] + se +")";
				stk.push(tmp);
			} else {
				stk.push(string(1,s[i]));
				// Tao 1 chuoi ky tu la s[i];
			}
		}
		cout<<stk.top()<<endl;
	}
	return 0;
}

