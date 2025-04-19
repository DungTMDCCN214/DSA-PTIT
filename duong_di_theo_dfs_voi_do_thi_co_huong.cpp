/*#include<bits/stdc++.h>

using namespace std;

int v, e, s, t;
vector<vector<int>> adj;
bool visited[1001];
vector<int> trace;
void nhap(){
	cin >> v >> e >> s >> t;
	adj.resize(v + 1);
	for (int i = 0; i < e;i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	memset(visited, false, sizeof(visited));
	trace.resize(v + 1);
	for (int i = 1; i <= v;i++){
		adj[i].clear();
		trace[i] = 0;
		visited[i] = 0;
	}
}
void dfs(int u){
	if(visited[u])
		return;
	visited[u] = true;
	for(int &i:adj[u]){
		if(!visited[i]){
			trace[i] = u;
			dfs(i);
		}
	}
}

void path(int s,int t){
	if(!trace[t]){
		cout << "-1";
		return;
	}
	vector<int> res;
	while(t!=s){
		if(!t){
			cout << "-1";
			return;
		}
		res.push_back(t);
		t = trace[t];
	}
	res.push_back(t);
	reverse(res.begin(), res.end());
	for(auto &i:res)
		cout << i << " ";
}
int main() {
	int z;
	cin >> z;
	while(z--){
		nhap();
		dfs(s);
		path(s, t);
		cout << endl;

	}
	return 0;
}*/


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
