#include<bits/stdc++.h>

using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        stack<string> stk;
        for (int i=a.length() - 1; i >= 0;i--){
            if(a[i]=='-' || a[i]=='+' || a[i]=='*' || a[i]=='/' || a[i]=='^'|| a[i]=='%'){
                string fi = stk.top();
                stk.pop();
                string se = stk.top();
                stk.pop();
                string tmp = fi + se + a[i];
                stk.push(tmp);
            } else {
                stk.push(string(1, a[i]));
            }
        }
        cout << stk.top()<<endl;
    }
}