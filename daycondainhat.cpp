#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	//l[i] : do dai cua day con dai nhat ket thuc o chi so i
	 //l[i] = max(l[i],l[j+1]) : a[i] > a[j]
	vector<int>l(n,1);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i] > a[j]){
				l[i]=max(l[i],l[j]+1);
			}
		}
	}
	cout<<*max_element(l.begin(), l.end())<<endl;
}

