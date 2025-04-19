#include<bits/stdc++.h>

using namespace std;

int n,k,a[1000];
vector<int> s;
set<vector<int>> res;

void back(int prev, int sum){
	for(int i=prev;i<=n;i++){
		if(sum+a[i]<=k){
			s.push_back(a[i]);
			if(sum+a[i]==k){
				res.insert(s);
			} else {
				back(i+1,sum+a[i]);
			}
			s.pop_back();
		}
	}
}
int main() {
	int t;
	cin>>t;
	while(t--){
		res.clear();
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		back(1,0);
		if(res.size()>=1){
			for(auto v:res){
				cout<<"[";
				for(int i=0;i<v.size();i++){
					cout<<v[i];
					if(i!=v.size()-1) cout<<" ";
				}
				cout<<"] ";
			}
		} else cout<<"-1";
		cout<<endl;
	}
	return 0;
}

