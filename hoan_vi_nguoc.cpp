#include<bits/stdc++.h>

using namespace std;
int n, a[100],check;

void khoitao(){
	for(int i=n;i>=1;i--){
		a[i]=n-i+1;
	}
}
void sinh(){
	int i=n-1;
	while(i>0 && a[i]<a[i+1]) i--;
	if(i==0) check=0;
	else {
		int j=n;
		while(a[i]<a[j]) j--;
		swap(a[i],a[j]);
		int l=i+1, r=n;
		while(l<r){
			swap(a[l],a[r]);
			l++;
			r--;
		}
	}
}
int main() {
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		check=1;
		khoitao();
		while(check){
			for(int i=1;i<=n;i++){
				cout<<a[i];
			}
			cout<<" ";
			sinh();
		}
		cout<<endl;
	}
	return 0;
}

