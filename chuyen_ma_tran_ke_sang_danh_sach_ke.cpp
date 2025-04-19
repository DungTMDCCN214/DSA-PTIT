#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	vector<vector<int>> a;
	for(int i=0;i<t;i++){
		vector<int> r;
		for(int j=0;j<t;j++){
			int x;	
			cin>>x;
			r.push_back(x);
		}
		a.push_back(r);
	} 
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			if(a[i][j]==1){
				cout<<j+1<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}

