#include <bits/stdc++.h>

using namespace std;

int n, u, count_cycles = 0;
vector<vector<int>> adj;
vector<int> path;
vector<bool> visited;
vector<vector<int>> cycles;

void findHamiltonianCycles(int pos) {
    if (pos == n) {
        if (adj[path[pos - 1]][u]) {
            count_cycles++;
            vector<int> cycle;
            for (int i = 0; i < n; i++) {
                cycle.push_back(path[i] + 1);
            }
            cycle.push_back(u + 1);
            cycles.push_back(cycle);
        }
        return;
    }
    
    for (int v = 0; v < n; v++) {
        if (!visited[v] && adj[path[pos - 1]][v]) {
            visited[v] = true;
            path[pos] = v;
            findHamiltonianCycles(pos + 1);
            visited[v] = false;
        }
    }
}

int main() {
    cin >> n >> u;
    u--; // Ðua v? ch? s? 0-based
    adj.assign(n, vector<int>(n));
    visited.assign(n, false);
    path.assign(n, -1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    
    path[0] = u;
    visited[u] = true;
    findHamiltonianCycles(1);
    
    cout << count_cycles << endl;
    for (const auto& cycle : cycles) {
        for (int x : cycle) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}

