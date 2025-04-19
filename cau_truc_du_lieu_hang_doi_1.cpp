#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		queue<int> u;
		int x;
		int y;
		while(n--){
			cin>>x;
			if(x==1) cout<<u.size()<<endl;
			else if(x==2){
				if(u.empty() )cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
			} else if(x==3){
				cin>>y;
				u.push(y); 
			} else if(x==4){
				if(!u.empty()){
					u.pop();
				}
			} else if(x==5){
				if(!u.empty())cout<<u.front()<<endl;
				else cout<<"-1"<<endl;
			} else {
				if(!u.empty()){
					cout<<u.back()<<endl;
				} else {
					cout<<"-1"<<endl;
				}
			}
		}
	}
	return 0;
}

