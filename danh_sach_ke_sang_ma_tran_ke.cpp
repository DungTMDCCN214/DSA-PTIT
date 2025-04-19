
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0)); 

    cin.ignore();
    
    for (int i = 1; i <= n; i++) {
        string line;
        getline(cin, line); 
        stringstream ss(line);
        int x;
        while (ss >> x) {
            a[i][x] = 1; 
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


