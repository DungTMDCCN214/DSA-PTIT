#include<bits/stdc++.h>

using namespace std;
int v,e;
int visited[1005];
vector<int> adj[1001];
// Dung mau 0,1,2 de duyet
// 0 la chua duoc tham
// 1 la co ton tai canh nguoc
// 2 la khong co chu trinh
bool dfs(int u){
	visited[u] = 1;
	for(auto x:adj[u]){
		if(visited[x]==0){
			if(dfs(x)){
				return true;
			}
		}
		else if(visited[x]==1){
			return true;
		}
	}
	visited[u] = 2;
	return false;
}
int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> v >> e;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i <= v;i++){
			adj[i].clear();
		}
		int ok = 0;
		for (int i = 1; i <= e;i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for (int i = 1; i <= v;i++){
			if(visited[i]==0){
				if(dfs(i)){
					cout << "YES" << endl;
					ok = 1;
					break;
				}
			}
		}
		if (ok==0) cout << "NO" << endl;
	}
	return 0;
}

