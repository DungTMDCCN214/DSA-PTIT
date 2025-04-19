#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 101;
vector<int> adj[MAX];
bool visited[MAX];
int n, m, s;

vector<pair<int, int>> dfs_edges;
vector<pair<int, int>> bfs_edges;

void DFS(int start) {
    stack<int> st;
    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dfs_edges.push_back({min(u, v), max(u, v)});
                st.push(u);
                st.push(v);
                break; // To process in lexicographical order
            }
        }
    }
}

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                bfs_edges.push_back({min(u, v), max(u, v)});
                q.push(v);
            }
        }
    }
}

int main() {
    ifstream fin("CK.INP");
    ofstream fout("CK.OUT");

    int t;
    fin >> t;
    fin >> n >> m >> s;

    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Sort adjacency lists for lexicographical order
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    if (t == 1) {
        memset(visited, false, sizeof(visited));
        DFS(s);

        if (dfs_edges.size() != n - 1) {
            fout << 0 << endl;
        } else {
            fout << n - 1 << endl;
            sort(dfs_edges.begin(), dfs_edges.end());
            for (auto edge : dfs_edges) {
                fout << edge.first << " " << edge.second << endl;
            }
        }
    } else if (t == 2) {
        memset(visited, false, sizeof(visited));
        BFS(s);

        if (bfs_edges.size() != n - 1) {
            fout << 0 << endl;
        } else {
            fout << n - 1 << endl;
            sort(bfs_edges.begin(), bfs_edges.end());
            for (auto edge : bfs_edges) {
                fout << edge.first << " " << edge.second << endl;
            }
        }
    }

    fin.close();
    fout.close();
    return 0;
}
