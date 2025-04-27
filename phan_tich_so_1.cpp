// Created by Nguy?n M?nh Qu�n

#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
/*
void push(vector<int> &v1, vector<string> &ans)
{
    vi v = v1;
    sort(v.begin(), v.end(), greater<int>());
    string s = "(";
    int size = v.sz - 1;
    F(i, 0, size)
    {
        s += to_string(v[i]);
        s += " ";
    }
    s += to_string(v[size]) + ")";
    ans.pb(s);
}

void Try(vi &v, int i, int n, vector<string> &ans)
{
    if (!n) push(v, ans);
    for (int j = n; j >= i; --j)
    {
        v.push_back(j);
        Try(v, j, n - j, ans);
        v.pop_back();
    }
}

int main()
{
    faster();
    int t = 1, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vi v;
        vector<string> ans;
        Try(v, 1, n, ans);
        sort(ans.begin(), ans.end(), greater<string>());
        if(n == 10)
        {
            cout << "(10) ";
            ans.erase(ans.begin() + 40);
        }
        for(string i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
*/
int n;
vector<int> a(21);
void in(int k){
    cout << "(";
    for (int i = 0; i < k;i++){
        if(i>0)
            cout << " ";
        cout << a[i];
    }
    cout << ")";
    cout << " ";
}

void Try(int i, int sum, int p){
    for (int j = p; j >= 1;j--){
        a[i] = j;
        int res = sum + j;
        if(res==n)
            in(i + 1);
        else if(res<n){
            Try(i + 1, res, j);
        }
    }
}
int main() {
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        Try(0, 0, n);
        cout << endl;
    }
    return 0;
}