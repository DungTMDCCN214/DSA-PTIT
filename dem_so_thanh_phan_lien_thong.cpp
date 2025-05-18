#include<bits/stdc++.h>

using namespace std;
// Luu y ve bo nho danh sach ke cho la v+10;
int v,e;
int cnt;
vector<vector<int>> adj;
bool visited[2000];

void dfs(int i){
	if (visited[i] == true){
		return;
	}
	visited[i] = true;
	for(auto x:adj[i]){
		if(visited[x]==false){
			dfs(x);
		}
	}
}
void check(){
	for (int i = 1; i <= v;i++){
		if (visited[i] == false){
			cnt++;
			dfs(i);
		}
	}
}
int main() {
	int t;
	cin>>t;
	while(t--){

		memset(visited, false, sizeof(visited));
		cnt = 0;
		cin >> v >> e;
		adj.resize(v + 10);
		for (int i = 0; i <= v;i++){
			adj.clear();
		}
			while (e--)
			{
				int x, y;
				cin >> x >> y;
				adj[x].push_back(y);
				adj[y].push_back(x);
			}
		check();
		cout << cnt << endl;
	}
	return 0;
}

