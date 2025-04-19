#include<bits/stdc++.h>

using namespace std;
string s;
int a[100],used[100],n;

void Try(int i){
	for(int j=1;j<=n;j++){
		if(used[j]==0){
			a[i]=j;
			used[j]=1;
			if(i==n) {
				for(int i=1;i<=n;i++){
					cout<<s[a[i]-1];
				}
				cout<<" ";
			}
			else Try(i+1);
			used[j]=0;
		}
	}
}
int main() {
	memset(used,0,sizeof(used));
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		n=s.size(); 
		Try(1);
		cout<<endl;
	}
	return 0;
}

