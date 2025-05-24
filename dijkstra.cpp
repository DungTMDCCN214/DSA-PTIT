#include<bits/stdc++.h>

using namespace std;

const int inf = 1e9;
int n,m,s;
vector<pair<int, int>> adj[1005];
int d[1005];

void Dijkstra(){
	for (int i = 1; i <= n;i++){
		d[i] = inf;
	}
	d[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	while(pq.size()){
		int u = pq.top().second;
		pq.pop();
		for(pair<int,int> p:adj[u]){
			int w = p.first;
			int v = p.second;
			if(d[v]>d[u]+w){
				d[v] = d[u] + w;
				pq.push({d[v], v});
			}
		}
	}

	for (int i = 1; i <= n;i++){
		cout << d[i] << " ";
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m >> s;
		while(m--){
			int u, v,w;
			cin >> u >> v >> w;
			adj[u].push_back({w, v});
			adj[v].push_back({w, u});
		}
		Dijkstra();
		cout << endl;

		for (int i = 1; i <= n;i++){
			adj[i].clear();

		}
	}
	return 0;
}

