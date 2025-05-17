/*#include<bits/stdc++.h>

using namespace std;

int v, u, check[100] = {0};
int a[1000][1000] = {0};

void dfs(int u){
	stack<int> s;
	check[u] = 1;
	s.push(u);
	while(!s.empty()){
		int k = s.top();
		s.pop();
		for (int i = 1; i <= v;i++){
			if(a[k][i]==1 && check[i]==0){
				check[i] = 1;
				s.push(k);
				s.push(i);
				break;
			} 
		}
	}
}
int main() {
	int z;
	cin >> z;
	while(z--){
		int n, e;
		cin >> n >> e >> v >> u;
		while(e--){
			int x, y;
			cin >> x >> y;
			a[x][y] = 1;
			a[y][x] = 1;
		}

	}
	return 0;
}

*/


#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
bool visited[1001];
vector<int> trace;

void nhap(int &v, int &e, int &s, int &t) {
    cin >> v >> e >> s >> t;
    adj.resize(v + 1);
    for (int i = 0; i <= v; i++) {
        adj[i].clear();
    }
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
		adj[y].push_back(x);
	}
    memset(visited, false, sizeof(visited));
    trace.resize(v + 1);
    fill(trace.begin(), trace.end(), 0);
}

void dfs(int u) {
    if (visited[u])
        return;
    visited[u] = true;
    for (int &i : adj[u]) {
        if (!visited[i]) {
            trace[i] = u;
            dfs(i);
        }
    }
}

void path(int s, int t) {
    if (!trace[t] && s != t) {  // Check if t is unreachable (except when s == t)
        cout << "-1";
        return;
    }
    vector<int> res;
    int current = t;
    while (current != s) {
        if (current == 0) {  // This handles cases where the path is broken
            cout << "-1";
            return;
        }
        res.push_back(current);
        current = trace[current];
    }
    res.push_back(s);
    reverse(res.begin(), res.end());
    for (auto &i : res)
        cout << i << " ";
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        int v, e, s, t;
        nhap(v, e, s, t);
        dfs(s);
        path(s, t);
        cout << endl;
    }
    return 0;
}