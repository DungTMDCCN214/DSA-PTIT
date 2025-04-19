#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n1,n2,n3;
		cin>>n1>>n2>>n3;
		long long a[n1],b[n2],c[n3];
		for(int i=0;i<n1;i++){
			cin>>a[i];
		}
		for(int i=0;i<n2;i++){
			cin>>b[i];
		}
		for(int i=0;i<n3;i++){
			cin>>c[i];
		}
		vector <long long> res;
		int i=0,j=0,z=0;
		while(i<n1 && j<n2 && z<n3){
			if(a[i]==b[j] && b[j]==c[z]){
				res.push_back(a[i]);
				i++,j++,z++;
			} else if(a[i]<b[j]){
				i++;
			} else if(b[j]<c[z]){
				j++;
			} else z++;
		}
		if(res.empty()) cout<<"-1";
		else {
			for(auto i:res){
				cout<<i<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}

