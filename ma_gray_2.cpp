#include<bits/stdc++.h>

using namespace std;


/*
dùng xor
-> bit đầu tiên giữ nguyên 
-> Từ bit thứ 2 den xor với bit cuối của xâu nhị phân
-> Kết quả xor chính là bit np của bước tương ứng

VS:10110
b1: 1
b2: 1+(1 xor 0) = 11
b3: 11 + (1 xor 1) =110
b4: 110 + (0 xor 1) = 1101
b5: 1101 + (1 xor 0) = 11011
10110 -> 11011
ky hieu ^ xor
*/
int main() {
	int t;
	cin >> t;
	while(t--){
		string a;
		cin >> a;
		for (int i = 1; i < a.length();i++){
			a[i] = ((a[i] - '0') ^ (a[i - 1] - '0')) +'0';
		}
		cout << a << endl;
	}
	return 0;
}

