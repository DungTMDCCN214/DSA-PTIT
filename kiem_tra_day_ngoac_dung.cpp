#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        stack<char> a;
        bool ok = true;
        for (int i = 0; i < s.size(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                a.push(s[i]);
            } else {
                if(a.empty()){
                    ok = false;
                    break;
                }
                char top = a.top();
                a.pop();
                if((s[i]==')' && top!='(') || 
                   (s[i]==']' && top!='[') || 
                   (s[i]=='}' && top!='{')){
                    ok = false;
                    break;
                }
            }
        }
        if(ok && a.empty()){
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}