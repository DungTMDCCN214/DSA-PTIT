#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int maxn = 100001;
int n, m,s,t;
vector<pair<int, int>> adj[maxn];

void nhap(){
	cin >> n >> m>>s>>t;
	for (int i = 0; i < m;i++){
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
}

const int INF = 1e9;
int pre[maxn];
void dijkstra(int s, int t){
	vector<ll> d(n + 1, INF);
	// Co the dung visited danh dau dinh da duyet r
	vector<bool> visited(n+1, false);
	d[s] = 0;
	pre[s] = s;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	// Khoang cach, dinh;
	// greater la ly ra phan tu be nhat;
	Q.push({0, s});
	while(!Q.empty()){
		pair<int, int> top = Q.top();
		Q.pop();
		int u = top.second;//Dinh
		int kc = top.first; // Khoang cach;
		//if(kc>d[u]) Su dung neu khong dung visited danh dau
		if(visited[u]== true)
			continue;
		visited[u] = true;
		// Relaxation : Cap nhat khoang cach tu s cho toi moi dinh ke voi u
		for(auto it:adj[u]){
			int v = it.first;
			int w = it.second;
			if(d[v]>d[u]+w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
				pre[v] = u;
			}
		}
	}
	cout << d[t]<<endl;
	vector<int> path;
	while(1){
		path.push_back(t);
		if(t==s){
			break;
		}
		t = pre[t];
	}
	reverse(begin(path), end(path));
	for(auto x:path){
		cout << x << " ";
	}
}
int main() {
	nhap();
	dijkstra(s,t);
	return 0;
}

