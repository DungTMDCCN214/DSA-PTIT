#include<bits/stdc++.h> 
using namespace std;

int v, e, a;
vector<int> adj[1000];
bool visited[1001];
void nhap(){
    cin >> v >> e >> a;
    for (int i = 0; i < e;i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u){
    cout << u << " ";
    visited[u] = true;
    for (int v:adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main() {
    int t;
    cin >> t;
    while(t--){
        nhap();
        dfs(a);
        cout<<endl;
        for(int i=0;i<1005;i++){
        	visited[i]=false;
        	adj[i].clear();
		}
    }
    return 0;
}
