#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> k(100005);
vector<bool> check(100005);

void DFS(int u){
	check[u]=1;
	cout<<u<<" ";
	for(int i=0;i<k[u].size();i++){
		if(check[k[u][i]]==0){
			DFS(k[u][i]);
		}
	}
} 

int main() {
	int t;
	cin>>t;
	while(t--){
		int v,e,u,x,y;
		cin>>v>>e>>u;
		for(int i=1;i<=v;i++){
			k[i].clear();
			check[i]=0;
		}
		while(e--){
			cin>>x>>y;
			k[x].push_back(y);
			k[y].push_back(x);
		}
		DFS(u);
		cout<<endl;
	}
}
