#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 10000;
const int MAX = 101;

struct Edge {
    int u, v, weight;
};

int n;
int parent[MAX];
int c[MAX][MAX];

bool compareEdges(const Edge &a, const Edge &b) {
    if (a.weight != b.weight)
        return a.weight < b.weight;
    if (a.u != b.u)
        return a.u < b.u;
    return a.v < b.v;
}

int findParent(int u) {
    if (parent[u] == u)
        return u;
    return parent[u] = findParent(parent[u]);
}

bool unionSets(int u, int v) {
    u = findParent(u);
    v = findParent(v);
    if (u != v) {
        parent[v] = u;
        return true;
    }
    return false;
}

vector<Edge> kruskalMST() {
    vector<Edge> edges;
    vector<Edge> mst;

    // Tạo danh sách cạnh từ ma trận
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (c[i][j] < INF) {
                edges.push_back({i, j, c[i][j]});
            }
        }
    }

    // Sắp xếp các cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end(), compareEdges);

    // Khởi tạo DSU
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // Duyệt qua các cạnh
    for (const Edge &e : edges) {
        if (unionSets(e.u, e.v)) {
            mst.push_back(e);
            if (mst.size() == n - 1)
                break;
        }
    }

    return mst;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] == 0 && i != j) {
                c[i][j] = INF;
            }
        }
    }

    vector<Edge> mst = kruskalMST();

    if (mst.size() != n - 1) {
        cout << 0 << endl;
    } else {
        int totalWeight = 0;
        for (const Edge &e : mst) {
            totalWeight += e.weight;
        }
        cout << totalWeight << endl;
        for (const Edge &e : mst) {
            cout << e.u << " " << e.v << " " << e.weight << endl;
        }
    }

    return 0;
}