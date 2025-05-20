#include<bits/stdc++.h>

using namespace std;
int v,e;
bool visited[1005];
vector<vector<int>> adj;
int ok;
void dfs(int u, int par){
	if(ok==1)
		return;
	visited[u] = true;
	for(auto x:adj[u]){
		if(visited[x]==false){
			dfs(x, u);
		} else if(x!=par){
			// Vi no da tham qua roi nen co the di qua 1 vai canh de quay lai dinh do;
			ok = 1;
			return;
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> v >> e;
		adj.resize(v + 1);
		ok = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i <= v;i++){
			adj[i].clear();
		}
		for (int i = 1; i <= e;i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for (int i = 1; i <= v;i++){
			memset(visited, false, sizeof(visited));
			dfs(i, 0);
			if(ok==1){
				break;
			}
		}
		if(ok==1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

