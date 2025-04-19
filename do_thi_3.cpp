#include<bits/stdc++.h>


using namespace std;
ifstream fin("DT.INP");
ofstream fout("DT.OUT");
int main() {
    int t, n;
    fin >> t >> n;
    
    vector<vector<int>> adjMatrix(n, vector<int>(n));
    vector<int> degree(n, 0);
    vector<pair<int, int>> edges;
    
    // �?c ma tr?n k? v� x�c �?nh b?c c�c �?nh
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> adjMatrix[i][j];
            if (adjMatrix[i][j] == 1 && i < j) { // Tr�nh �?m c?nh hai l?n
                edges.push_back({i, j});
            }
            if (adjMatrix[i][j] == 1) {
                degree[i]++;
            }
        }
    }
    
    if (t == 1) {
        // In b?c c?a c�c �?nh
        for (int i = 0; i < n; i++) {
            fout << degree[i] << " ";
        }
    } else {
        int m = edges.size();
        vector<vector<int>> incidenceMatrix(n, vector<int>(m, 0));
        
        // Duy?t qua danh s�ch c?nh v� t?o ma tr?n li�n thu?c
        for (int i = 0; i < m; i++) {
            int u = edges[i].first;
            int v = edges[i].second;
            incidenceMatrix[u][i] = 1;
            incidenceMatrix[v][i] = 1;
        }
        
        // In ma tr?n li�n thu?c
        fout << n << " " << m << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                fout << incidenceMatrix[i][j] << " ";
            }
            fout << endl;
        }
    }
    fin.close();
    fout.close();

    return 0;
}

