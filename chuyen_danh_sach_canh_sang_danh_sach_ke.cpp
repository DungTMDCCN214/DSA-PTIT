#include<bits/stdc++.h>

using namespace std;
struct k{
	int dau, cuoi;
};
int main() {
	int t;
	cin>>t;
	while(t--){
		int e,v;
		cin>>e>>v;
		vector<k> ke(v); 
		for(int i=0;i<v;i++){
			cin>>ke[i].dau>>ke[i].cuoi;
		}
		for(int i=1;i<=e;i++){
			cout<<i<<": ";
			for(int j=0;j<v;j++){
				if(ke[j].dau==i) cout<<ke[j].cuoi<<" ";
				if(ke[j].cuoi==i) cout<<ke[j].dau<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

