
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
vector<int> adj[MAX];
int n, m, u;
vector<vector<int>> cycles;
vector<int> path;
bool visited[MAX];

void dfs(int current, int count) {
    if (count == n) {
        // Kiểm tra có cạnh từ current về u không
        for (int v : adj[current]) {
            if (v == u) {
                vector<int> cycle = path;
                cycle.push_back(u);
                cycles.push_back(cycle);
                break;
            }
        }
        return;
    }

    for (int v : adj[current]) {
        if (!visited[v]) {
            visited[v] = true;
            path.push_back(v);
            dfs(v, count + 1);
            path.pop_back();
            visited[v] = false;
        }
    }
}

int main() {


    cin >> n >> m >> u;
    for (int i = 0; i < m; i++) {
        int ui, vi;
        cin >> ui >> vi;
        adj[ui].push_back(vi);
    }

    // Khởi tạo
    memset(visited, false, sizeof(visited));
    path.push_back(u);
    visited[u] = true;
    dfs(u, 1);

    // Xuất kết quả
    cout << cycles.size() << endl;
    for (auto cycle : cycles) {
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << endl;
    }


    return 0;
}