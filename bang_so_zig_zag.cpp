#include<bits/stdc++.h>

using namespace std;

long long timhang(long long z){
	long long hang=(int)sqrt(2*z);
	
}
int main() {
	long long  x,y;
	cin>>x>>y;
	long long  z;
	cin>>z;
	cout<<(x*(x-1)/2+1) + (y-1)*(x+1)<<endl;
	long long hang = timhang(z);
	long long a=hang*(hang-1)/2+1;
	
	long long cot=(z-a)/(hang+1) + 1;
	cout<<hang<<" "<<cot;
	return 0;
}

