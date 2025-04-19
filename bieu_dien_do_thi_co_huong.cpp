#include<bits/stdc++.h>

using namespace std;

struct k{
	int dau,cuoi;
};
int main() {
	int t;
	cin>>t;
	while(t--){
		int v,e;
		cin>>v>>e;
		vector<k> ke(e+1);
		for(int i=1;i<=e;i++){
			cin>> ke[i].dau>>ke[i].cuoi;
		}
		for(int i=1;i<=v;i++){
			cout<<i<<": ";
			for(int j=1;j<=e;j++){
				if(ke[j].dau==i){
					cout<<ke[j].cuoi<<" ";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}

