


#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9; // Giá trị vô cùng lớn, đại diện cho không có đường đi
int n, m;
int trace[105][105];
int d[105][105];

//Neu tim duong di
void printPath(int u, int v){
	if(u==v)
		cout << u;
	return;
	if(trace[u][v]==-1){
		cout << "-1";
	}
	return;
	printPath(u, trace[u][v]);
	cout << v << " ";
}

void floyd() {
    // Khởi tạo trace
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            trace[u][v] = u;
        }
    }

    // Thuật toán Floyd-Warshall
    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (d[u][k] < INF && d[k][v] < INF && d[u][v] > d[u][k] + d[k][v]) {
                    d[u][v] = d[u][k] + d[k][v];
                    trace[u][v] = trace[k][v];
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    // Khởi tạo ma trận khoảng cách
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    // Nhập các cạnh
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        d[x][y] = z;
        d[y][x] = z;
    }

    floyd();

    int q;
    cin >> q;
    while (q--) {
        int b, c;
        cin >> b >> c;
		cout << d[b][c] << endl;
	}

    return 0;
}