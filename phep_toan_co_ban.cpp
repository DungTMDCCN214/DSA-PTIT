#include<bits/stdc++.h>

using namespace std;
string s, x;
char c[] = {'+', '-', '*', '/'};
bool ok;
bool check(){
	int a = (s[0] - '0') * 10 + (s[1] - '0');
	int b = (s[5] - '0') * 10 + (s[6] - '0');
	int c = (s[10] - '0') * 10 + (s[11] - '0');
	if(s[3]=='+'){
		return a + b == c;
	} else if(s[3]=='-'){
		return a - b == c;
	}else if(s[3]=='/'){
		return a / b == c;
	} else
		return a * b == c;
}

void Try(int i){
	if(ok==1)
		return;
	if(i==x.size()){
		if(check()){
			cout << s << endl;
			ok = 1;
		}
		return;
	}
	if(x[i]!='?'){
		Try(i + 1);
	} else if(i==3){
		for (int j = 0; j < 4;j++){
			s[i] = c[j];
			Try(i + 1);
		}
	} else {
		for (int j = 0; j <= 9;j++){
			if(j==0){
				if(i==0 || i==5 || i==10){
					continue;
				}
			}
			s[i] = j + '0';
			Try(i + 1);
		}
	}
}
int main() {
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		getline(cin, x);
		s=x;
		ok = 0;
		Try(0);
		if(ok==0)
			cout << "WRONG PROBLEM!" << endl;
	}
	return 0;
}























/*
bool check(){
	int a = (s[0] - '0') * 10 + (s[1] - '0');
	int b = (s[5] - '0') * 10 + (s[6] - '0');
	int c = (s[10] - '0') * 10 + (s[11] - '0');

	if (s[3] == '+')
		return a + b == c;
	if(s[3]=='-'){
		return a - b == c;
	} 
	if(s[3]=='*') {
		return a * b == c;
	}
	if(s[3]=='/'){
		return a / b == c;
	}
}

void Try(int i){
	if(ok==1)
		return;
	if(i==x.size()){
		if(check()){
			ok = 1;
			cout << s<<endl;
		}
		return;
	}
	if(x[i]!='?')
		Try(i + 1);
	else if(i==3){
		for (int j = 0; j < 4;j++){
			s[i] = c[j];
			Try(i + 1);
		}
	} else {
		for (int j = 0; j <= 9;j++){
			if(j==0){
				if(i==0 || i==5 || i==10){
					continue;
				}
			}
			s[i] = j+'0';
			Try(i + 1);
		}
	}
}
int main() {
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		getline(cin, x);
		s = x;
		ok = 0;
		Try(0);
		if(ok==0)
			cout << "WRONG PROBLEM!" << endl;
	}
	return 0;
}
*/
