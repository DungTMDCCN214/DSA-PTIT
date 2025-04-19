#include<bits/stdc++.h>



using namespace std;

const int MAX_N = 100;
int adjMatrix[MAX_N][MAX_N]; // Ma tr?n k?
int degree[MAX_N]; // B?c c?a m?i ð?nh
int n, u;

// Ki?m tra ð? th? có liên thông không (ch? xét các ð?nh có c?nh)
bool isConnected() {
    vector<bool> visited(n, false);
    stack<int> st;
    int start = -1;
    
    for (int i = 0; i < n; i++) {
        if (degree[i] > 0) {
            start = i;
            break;
        }
    }
    if (start == -1) return false;

    st.push(start);
    visited[start] = true;
    int count = 1;

    while (!st.empty()) {
        int v = st.top();
        st.pop();
        for (int i = 0; i < n; i++) {
            if (adjMatrix[v][i] && !visited[i]) {
                visited[i] = true;
                st.push(i);
                count++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (degree[i] > 0 && !visited[i]) return false;
    }
    return true;
}

// Ki?m tra lo?i Euler
int checkEuler() {
    if (!isConnected()) return 0;
    
    int odd_count = 0;
    for (int i = 0; i < n; i++) {
        if (degree[i] % 2 != 0) odd_count++;
    }
    
    if (odd_count == 0) return 1; // Euler
    else if (odd_count == 2) return 2; // N?a Euler
    return 0;
}

// T?m chu tr?nh Euler
void findEulerCycle(int start) {
    stack<int> st;
    vector<int> circuit;
    
    st.push(start);
    while (!st.empty()) {
        int v = st.top();
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (adjMatrix[v][i]) {
                st.push(i);
                adjMatrix[v][i]--;
                adjMatrix[i][v]--;
                found = true;
                break;
            }
        }
        if (!found) {
            circuit.push_back(v + 1);
            st.pop();
        }
    }
    reverse(circuit.begin(), circuit.end());
    for (int v : circuit) cout << v << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    
    if (t == 1) {
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> adjMatrix[i][j];
                degree[i] += adjMatrix[i][j];
            }
        }
        
        cout << checkEuler() << endl;
    } 
    else if (t == 2) {
        cin >> n >> u;
        u--; // Chuy?n v? ch? m?c 0-based
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> adjMatrix[i][j];
            }
        }
        
        findEulerCycle(u);
    }
    return 0;
}


