#include <bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<vector>
#include<string>

#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define ll long long
#define fi first
#define se second
#define vt vector
#define db double
#define endl "\n"

const int mx = 1e5;
const int mod = 1e9+7;
#define TEST 0

int n, a[100], check;

void khoitao(){
	for(int i=1;i<=n;i++){
		a[i]=0;
	}
}
int k;
int solve(int a[]){
	int sum=0;
	int count=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			count++;
			sum++;
		} else {
			count=0;
		}
	}
	if(count==k && sum==k) return 1;
	else return 0;
}
void sinh() {
	int i=n;
	while(i>=1 && a[i]==1){
		a[i]=0;
		i--;
	}
	if(i==0){
		check=0;
	} else {
		a[i]=1;
	}
}

int main() {
		cin>>n;
		cin>>k;
		check=1;
		khoitao();
			while(check){
				if(solve(a)==1){
					for(int i=1;i<=n;i++){
						cout<<a[i];
					}
				cout<<endl;
			}
				sinh();
		}
		cout<<endl;
}

