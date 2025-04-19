#include<bits/stdc++.h>

using namespace std;

int main() {
	int n,k;
	cin>>n;
	while(n--){
		cin>>k;
		vector<int> a(k);
		bool check =0;
		for(int i=0;i<k;i++){
			cin>>a[i];
			if(a[i]>0) check =1;
		}
		int m=-101;
		if(!check) for(int i=0;i<k;i++){
			m=max(a[i],m);
		} else {
			int sum =0;
			for(int i=0;i<k;i++){
				sum+=a[i];
				if(sum<0) sum=0;
				m=max(sum,m);
			}
		}
		cout<<m<<endl;
	} 
	return 0;
}

