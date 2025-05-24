#include<bits/stdc++.h>

using namespace std;

vector<int> adj[1005];
int n,m,s;
bool check[1001];
vector<pair<int, int>> ans;

void dfs(int u){
	check[u] = 1;
	for(int v:adj[u]){
		if(check[v]==0){
			ans.push_back({u, v});
			dfs(v);
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m >> s;
		while(m--){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(s);
		if(ans.size()!=n-1){
			cout<<"-1"<<endl;
		} else {
			for(auto x:ans){
				cout << x.first << " " << x.second<<endl;
			}
		}
		for (int i = 1; i <= n;i++){
			adj[i].clear();
			check[i] = 0;
		}
		ans.clear();
	}
	return 0;
}

