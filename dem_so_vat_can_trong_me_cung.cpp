#include<bits/stdc++.h>

using namespace std;
int n,m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
 vector<string> vs;
 bool check(int x,int y){
 	return (x>=0 && y>=0 && x<n && y<m&& vs[x][y]=='#');
 }
 
 void DFS(int x,int y){
 	if(check(x,y)){
 		vs[x][y]='.';
 		for(int i=0;i<4;i++){
 			DFS(x+dx[i],y+dy[i]);
		 }
	 }
 }
int main() {
	cin>>n>>m;
	string s;
	while(cin>>s){
		vs.push_back(s);
	}
	int res=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vs[i][j]=='#'){
				res++;
				DFS(i,j);
			}
		}
	}
	cout<<res;
	return 0;
}

