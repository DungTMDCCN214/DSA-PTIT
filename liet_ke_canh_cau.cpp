#include<bits/stdc++.h>

using namespace std;

/*
id ,min
id: Thu tu duyet
min: dinh co thu tu thap nhat co the den

minh den 1 dinh thi se gan id++ = min
khi quay lai:
1, cap nhat min[u] = min(min[u], min[v]);
2, neu min[v]>id[u] -> canh cau
*/

vector<int> adj[1001];
int n, m;
int id[1001], mi[1001],cnt;
vector<pair<int, int>> ans;
void dfs(int u, int par){
	id[u] = mi[u] = cnt++;
	for(int v:adj[u]){
		if(v==par)
			continue;
		if(id[v])
			mi[u] = min(mi[u], mi[v]);
		else {
			dfs(v, u);
			mi[u] = min(mi[u], mi[v]);
			if(mi[v]>id[u]){
				if(u<v){
					ans.push_back({u, v});
				} else {
					ans.push_back({v, u});
				}
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int u, v;
		while(m--){
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cnt = 1;
		dfs(1, 0);
		sort(ans.begin(), ans.end());
		for(auto p:ans){
			cout << p.first << " "<<p.second<<" ";
		}
		cout << endl;
		for (int i = 1; i <= n;i++){
			adj[i].clear();
			id[i] = 0;
			mi[i] = 0;

		}
		ans.clear();
	}
	return 0;
}

