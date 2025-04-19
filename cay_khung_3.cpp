#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 105;
int n, s;
vector<int> adj[MAX];
bool visited[MAX];
vector<pair<int, int>> tree_edges;

void DFS(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            tree_edges.push_back({u, v});
            DFS(v);
        }
    }
}

void BFS(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                tree_edges.push_back({u, v});
                q.push(v);
            }
        }
    }
}

int main() {
    int t;
    cin >> t >> n >> s;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }

    fill(visited, visited + MAX, false);
    tree_edges.clear();

    if (t == 1) {
        DFS(s);
    } else if (t == 2) {
        BFS(s);
    }

    if (tree_edges.size() < n - 1) {
        cout << 0 << endl;
    } else {
        cout << tree_edges.size() << endl;
        for (auto edge : tree_edges)
            cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}