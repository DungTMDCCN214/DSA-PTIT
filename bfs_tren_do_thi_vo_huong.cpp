#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> k(100005);
vector<bool> check(100005);
void BFS(int u){
	queue<int> q;
	q.push(u);
	check[u]=1;
	while(q.size()){
		u=q.front();
		cout<<u<<" ";
		q.pop();
		for(int i:k[u]){
			if(check[i]==0){
				q.push(i);
				check[i]=1;
			}
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
			check[i]=0;
			k[i].clear();
		}
		while(e--){
			cin>>x>>y;
			k[x].push_back(y);
			k[y].push_back(x);
		}
		BFS(u);
		cout<<endl;
	}
	return 0;
}

