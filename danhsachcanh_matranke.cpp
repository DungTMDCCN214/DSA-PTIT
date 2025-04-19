#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, m;
    cin >> t >> n >> m;
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));
    vector<int> degree(n, 0);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // Ðua v? ch? m?c 0-based
        adj_matrix[u][v] = adj_matrix[v][u] = 1;
        degree[u]++;
        degree[v]++;
    }
    
    if (t == 1) {
        for (int i = 0; i < n; i++) {
            cout << degree[i] << " ";
        }
    } else {
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}

