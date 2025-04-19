#include<bits/stdc++.h>

using namespace std;
int n;
int a[100]={};
vector<string> v;
vector<int> tmp;
void in(){
	string s="";
	for(int i:tmp) {
		s+=to_string(i) + " ";
	}
	v.push_back(s);
}

void Try(int i){
	for(int j=i+1;j<=n;j++){
		if(a[j]>a[i]){
			tmp.push_back(a[j]);
			if(tmp.size()>1) in();
			Try(j);
			tmp.pop_back();
		}
	}
}
int main() {
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		Try(0);
		sort(v.begin(),v.end());
		// Sap xep theo thu tu tu dien; 
		for(string i: v) cout<<i<<endl;
	return 0;
}













