/*

#include<bits/stdc++.h>

using namespace std;
int a[1001][1001],n,X[1005],m,u;
bool chuaxet[1001];
vector<vector<int> > res;
void quay(int i,vector<int> k){
	for(int j=1;j<=n;j++){
		if(a[X[i-1]][j]&&chuaxet[j]){
			chuaxet[j]=false;
			X[i]=j;
			k.push_back(j);
		if(i==n+1&&j==u){
				res.push_back(k);
			}else {
				quay(i+1,k);
			}
			k.pop_back();
			chuaxet[j]=true;
		}
		}
	}

void khoitao(int g){
	X[1]=g;
	vector<int> t;
	t.push_back(g);
	quay(2,t);
}
int main() {
	memset(a,0,sizeof(a));
	memset(chuaxet,true,sizeof(chuaxet));
	cin>>n>>m>>u;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	khoitao(u);
	cout<<res.size()<<endl;
	if(res.size()){
		for(auto x:res){
			for(auto y:x){
				cout<<y<<' ';
			}
			cout<<endl;
		}
	}
	
}
*/

#include<bits/stdc++.h>
using namespace std;
int n, m, u;
int dem = 0;
int A[105][105];
bool chuaxet[105];
vector<vector<int>> ham;
int X[105];
void Hamilton(int k) {
	for (int i = 1;i <= n;i++) {
		if (A[X[k - 1]][i] == 1) {
			if (k == n + 1 && i == u) {
				vector<int> path;
				for (int j = 1;j <= n;j++) {
					path.push_back(X[j]);
				}
				path.push_back(u);
				ham.push_back(path);
				dem++;
			}
			else if (chuaxet[i] == 1) {
				X[k] = i;
				chuaxet[i] = 0;
				Hamilton(k + 1);
				chuaxet[i] = 1;
			}
		}
	}
}
void Xuat() {
	cout << dem << endl;
	for (auto& x : ham) {
		for (int i = 0;i < x.size();i++) {
			cout << x[i] << " ";
		}
		cout << endl;
	}
}
int main() {
	//freopen("CT.INP", "r", stdin);/*
	//freopen("CT.OUT", "w", stdout);*/
	cin >> n >> m >> u;
	for (int i = 1;i <= m;i++) {
		int x, y;
		cin >> x >> y;
		A[x][y] = 1;
		A[y][x] = 1;
	}
	X[1] = u;
	memset(chuaxet, 1, sizeof(chuaxet));
	chuaxet[u] = 0;
	Hamilton(2);
	Xuat();
}