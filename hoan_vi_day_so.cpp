#include<bits/stdc++.h>

using namespace std;
int n,a[100],check;	
void khoitao(){
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
}
void sinh(){
	int i=n-1;
	while(a[i]>a[i+1] && i>=1){
		i--;
	}
	if(i==0) check=0;
	else {
		int j=n;
		while(a[j]<a[i]) j--;
		swap(a[i],a[j]);
		int l=i+1,r=n;
		while(l<r){
			swap(a[l],a[r]);
			l++;
			r--;
		}
	}
}
int main() {
		cin>>n;
		int b[n];
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		sort(b,b+n);
		check=1;
		khoitao();
		while(check){
			for(int i=1;i<=n;i++){
				cout<<b[a[i]-1]<<" ";
			}
			cout<<endl;
			sinh();
		}
	return 0;
}

