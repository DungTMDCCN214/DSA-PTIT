#include<bits/stdc++.h>

using namespace std;

// De loai bo dinh dang xet thi chi can cho visited[i]=true la xong;
int v, e;
vector<vector<int>> adj;
bool visited[1005];
void dfs(int u){
	if(visited[u]==true){
		return;
	}
	visited[u] = true;
	for(auto x:adj[u]){
		if(visited[x]==false){
			dfs(x);
		}
	}
}
int check(){
	int cnt = 0;
	for (int i = 1; i <= v;i++){
		if(visited[i]==false){
			cnt++;
			dfs(i);
		}
	}
	return cnt;
}
int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> v >> e;
		memset(visited, false, sizeof(visited));
		adj.resize(v + 1);
		for (int i = 0; i <= v;i++){
			adj[i].clear();
		}

		for (int i = 1; i <= e;i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int k = check();
		for (int i = 1; i <= v;i++){
			memset(visited, false, sizeof(visited));
			visited[i] = true;
			if(k<check()){
				cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}

