#include<bits/stdc++.h>

using namespace std;


int main() {
	int t;
	cin>>t;
	vector<vector<int>> v(t+1);
	cin.ignore();
	int tmp;
	string s;
	for(int i=1;i<=t;i++){
		getline(cin,s);
		stringstream ss(s);
		while(ss>>s){
			tmp=stoi(s);
			v[i].push_back(tmp);
		}
	}
	for(int i=1;i<=t;i++){
		sort(v[i].begin(),v[i].end());
		for(auto j:v[i]){
			if(j>i) cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
}

