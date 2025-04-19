#include<bits/stdc++.h>

using namespace std;

int main() {
	int x;
	cin>>x;
	vector<int> a(x);
	for(int i=0;i<x;i++) {
		cin>>a[i];
	}
	vector<int> l(x,1);
	for(int i=0;i<x;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j]){
				l[i]=max(l[i],l[j]+1);
			}
		}
	}
	cout<<*max_element(l.begin(), l.end());
	return 0;
}

