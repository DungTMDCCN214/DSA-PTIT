#include<bits/stdc++.h>

using namespace std;


void check(vector<int> &a, vector<int> &b, vector<int> &c){
	int i=0,j=0,k=0;
	vector<int> result;
	
	while(i<a.size() && j<b.size() && k<c.size()){
		if(a[i]==b[j] && b[j]==c[k]){
			result.push_back(a[i]);
			i++;j++;k++;
		} else if(a[i]<b[j]) i++;
		else if(b[j]<c[k]) j++;
		else k++;
	}
	if(result.empty()) cout<<"NO";
	else {
		for(int x:result) cout<<x<<" ";
	}
	cout<<endl;
} 
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		vector<int> a(n),b(m),c(k);
		
		for(int &i:a) cin>>i;
		for(int &i:b) cin>>i;
		for(int &i:c) cin>>i;
		check(a,b,c);
	}
	return 0;
}

