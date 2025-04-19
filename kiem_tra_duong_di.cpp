#include<bits/stdc++.h>

using namespace std;
vector<int> adj[1001];
bool visited[1001];
int ok = 0;
void dfs(int l, int target){
	visited[l] = true;
	if(l==target){
		return;
	}
	for(auto x:adj[l]){
		if(!visited[x]){
			dfs(x,target);
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int x, y;
		while(m--){
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int z;
		cin >> z;
		int u, v;
		while(z--){
			cin >> u >> v;
			memset(visited, false, sizeof(visited));
			dfs(u,v);
			if(visited[v]){
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
		for (int i = 0; i <= n;i++){
			adj[i].clear();
		}
	}
	return 0;
}

