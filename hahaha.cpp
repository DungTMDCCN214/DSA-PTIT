#include<bits/stdc++.h>

using namespace std;

int n;
int a[100],check;
void khoitao(){
	for(int i=1;i<=n;i++){
		a[i]=0;
	}
} 
void sinh(){
	int i=n;
	while(i>=1 &&a[i]==1){
		a[i]=0;
		i--;
	}
	if(i==0) check=0;
	else {
		a[i]=1;
	}
}
int kt(int a[]){
	if(a[1]==0 ) return 0;
	else if(a[n]==1) return 0;
	else {
		for(int i=1;i<n;i++){
			if(a[i+1]==1 && a[i]==1) return 0;
		}
		return 1;
	}
}
void in(){
	for(int i=1;i<=n;i++){
		if(a[i]==1) cout<<"H";
		else cout<<"A";
	}
	cout<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		check=1;
		khoitao();
		while(check!=0){
			if(kt(a)){
				in();
			}
			sinh();
		}
	}
	return 0;
}

