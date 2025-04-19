#include<bits/stdc++.h>

using namespace std;
int n,k,a[100],check;
void khoitao(){
	for(int i=1;i<=k;i++){
		a[i]=i;
	}
} 
void sinh(){
	int i=k;
	while(a[i]==n-k+i && i>=1) i--;
	if(i==0) check=0;
	else {
		a[i]++;
		for(int j=i+1;j<=k;j++){
			a[j]=a[i]+j-i;
		}
	}
}
int main() {
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		check=1;
		khoitao();
		while(check){
			for(int i=1;i<=k;i++){
				cout<<char(a[i]+64);
			}
			cout<<endl;
			sinh();
		}
	}
	return 0;
}

