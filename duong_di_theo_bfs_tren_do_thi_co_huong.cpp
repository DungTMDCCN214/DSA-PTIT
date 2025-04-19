#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
bool visited[1001];
vector<int> trace;

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(q.size()){
		u = q.front();
		q.pop();
		for(auto i:adj[u]){
			if(!visited[i]){
				q.push(i);
				trace[i] = u;
				visited[i] = true;
			}
		}
	}
}
void path(int s, int t){
	if(!trace[t] && s!=t){
		cout << "-1";
		return;
	}
	vector<int> res;
	int current = t;
	while(current!=s){
		if(current==0){
			cout << "-1";
			return;
		}
		res.push_back(current);
		current = trace[current];
	}
	res.push_back(s);
	reverse(res.begin(), res.end());
	for(auto &i:res){
		cout << i << " ";
	}
}
int main() {
	int z;
	cin >> z;
	while(z--){
		int v, e, s, t;
		cin >> v >> e >> s >> t;
		adj.resize(v + 1);
		for (int i = 0; i <= v;i++){
			adj.clear();
		}
		for (int i = 0; i < e;i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		memset(visited, false, sizeof(visited));
		trace.resize(v + 1);
		fill(trace.begin(), trace.end(),0);
		bfs(s);
		path(s, t);
		cout << endl;
	}
	return 0;
}

