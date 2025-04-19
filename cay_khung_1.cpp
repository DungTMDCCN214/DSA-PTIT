#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 101;
int adj[MAX][MAX];
bool visited[MAX];
int n, s;

vector<pair<int, int>> dfs_edges;
vector<pair<int, int>> bfs_edges;

void DFS(int start) {
    stack<int> st;
    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        for (int v = 1; v <= n; ++v) {
            if (adj[u][v] && !visited[v]) {
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

        for (int v = 1; v <= n; ++v) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = true;
                bfs_edges.push_back({min(u, v), max(u, v)});
                q.push(v);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    cin >> n >> s;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> adj[i][j];
        }
    }

    if (t == 1) {
        memset(visited, false, sizeof(visited));
        DFS(s);

        if (dfs_edges.size() != n - 1) {
            cout << 0 << endl;
        } else {
            cout << n - 1 << endl;
            
            for (auto edge : dfs_edges) {
                cout << edge.first << " " << edge.second << endl;
            }
        }
    } else if (t == 2) {
        memset(visited, false, sizeof(visited));
        BFS(s);

        if (bfs_edges.size() != n - 1) {
            cout << 0 << endl;
        } else {
            cout << n - 1 << endl;
            
            for (auto edge : bfs_edges) {
                cout << edge.first << " " << edge.second << endl;
            }
        }
    }

    return 0;
}
