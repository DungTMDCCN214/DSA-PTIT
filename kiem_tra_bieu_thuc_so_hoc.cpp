#include<bits/stdc++.h>

using namespace std;
// Kiem tra xem trong cap ngoac cos dau nao khong;

string check (string s){
	stack<char> st;
	bool check;
	char k;
	for(char i:s){
		if(i==')'){
			check=0;
			k=st.top();
			st.pop();
			while(k!='('){
				if(k=='+' || k=='-' || k=='*' || k=='/'){
					check=1;
				}
				k=st.top();
				st.pop();
			}
			if(check==0) return "Yes";
		} else st.push(i);
	}
	return "No";
} 
int main() {
	int t;
	cin>>t;
	string a;
	cin.ignore();
	while(t--){
		getline(cin,a);
		cout<<check(a)<<endl;
		
	}
	return 0;
}

