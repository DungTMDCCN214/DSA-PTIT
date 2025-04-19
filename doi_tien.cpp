#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	int a[]={1,2,5,10,20,50,100,200,500,1000};
	while(t--){
		int n;
		cin>>n;
		int i=9,cnt=0;
		while(n!=0){
			cnt+=n/a[i];
			n%=a[i];
			i--;
		}
		cout<<cnt<<endl;
	}
	return 0;
}

