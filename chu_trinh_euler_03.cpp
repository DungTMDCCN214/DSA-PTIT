#include<bits/stdc++.h>


using namespace std;

vector<vector<int>> adj;
vector<int> in_degree, out_degree;
int n;

bool isConnected() {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    
    int start = -1;
    for (int i = 1; i <= n; i++) {
        if (!adj[i].empty()) {
            start = i;
            break;
        }
    }
    
    if (start == -1) return true;
    
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (!adj[i].empty() && !visited[i]) return false;
    }
    return true;
}


int checkEuler() {
    if (!isConnected()) return 0;
    
    int start_nodes = 0, end_nodes = 0;
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] - in_degree[i] == 1) start_nodes++;
        else if (in_degree[i] - out_degree[i] == 1) end_nodes++;
        else if (in_degree[i] != out_degree[i]) return 0;
    }
    
    if (start_nodes == 0 && end_nodes == 0) return 1;
    if (start_nodes == 1 && end_nodes == 1) return 2; 
    return 0;
}


void eulerCycle(int u) {
    stack<int> st;
    vector<int> circuit;
    vector<vector<int>> temp_adj = adj;
    
    st.push(u);
    while (!st.empty()) {
        int v = st.top();
        if (!temp_adj[v].empty()) {
            int w = temp_adj[v].back();
            temp_adj[v].pop_back();
            st.push(w);
        } else {
            circuit.push_back(v);
            st.pop();
        }
    }
    
    reverse(circuit.begin(), circuit.end());
    for (int v : circuit) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    
    if (t == 1) {
        cin >> n;
        adj.assign(n + 1, vector<int>());
        in_degree.assign(n + 1, 0);
        out_degree.assign(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int v;
                cin >> v;
                adj[i].push_back(v);
                out_degree[i]++;
                in_degree[v]++;
            }
        }
        
        cout << checkEuler() << endl;
    } 
    else if (t == 2) {
        int u;
        cin >> n >> u;
        adj.assign(n + 1, vector<int>());
        
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int v;
                cin >> v;
                adj[i].push_back(v);
            }
        }
        
        eulerCycle(u);
    }
    
    return 0;
}


