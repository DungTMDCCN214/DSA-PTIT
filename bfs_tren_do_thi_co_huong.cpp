#include<bits/stdc++.h>

using namespace std;
vector<int> k[1005];
bool check[1005];
void BFS(int s){
	queue<int> q;
	q.push(s);
	check[s] = 1;
	while(q.size()){
		int u = q.front();
		q.pop();
		cout << u << " ";
		for(int i:k[u])
			{
				if(check[i]==0){
					q.push(i);
					check[i] = 1;
				}
			}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		int v, e, u;
		cin >> v >> e >> u;
		while(e--){
			int x, y;
			cin >> x >> y;
			k[x].push_back(y);
		}
		BFS(u);
		cout << endl;
		for (int i = 0; i < 1005;i++){
			check[i] = 0;
			k[i].clear();
		}
	}
	return 0;
}

