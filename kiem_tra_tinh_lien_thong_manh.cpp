#include<bits/stdc++.h>

using namespace std;

int v, e;
vector<vector<int>> adj(1005);
bool visited[1005];
// Kiem tra nhu lien thong va no chi co 1 thanh phan lien thong
void BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int k = q.front();
		q.pop();
		for(auto x:adj[k]){
			if(visited[x]==false){
				q.push(x);
				visited[x] = true;
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> v >> e;
		int cnt = 0;
		//adj.resize(v + 1);
		memset(visited, false, sizeof(visited));
		for (int i = 0; i <= v;i++){
			adj[i].clear();
		}
			for (int i = 1; i <= e; i++)
			{
				int x, y;
				cin >> x >> y;
				adj[x].push_back(y);
			}

			for (int i = 1; i <= v;i++){
				if(visited[i]==false){
					cnt++;
					BFS(i);
				}
			}
			if(cnt>=2)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
	}
	return 0;
}

