#include<bits/stdc++.h>

using namespace std;
int n, k;
vector<int> a(16);
vector<vector<int>> ans;
// sinh quay lui;

bool kt(){
	int cntA = 0;
	int cnt = 0;
	for (int i = 1; i <= n;i++){
		if(a[i]==0)
			cntA++;
		else
			cntA = 0;
		if(cntA>k)
			return 0;
		cnt += (cntA == k);
		
	}
	return cnt == 1;
}
void tryAt(int i){
	for (int j = 0; j <= 1;j++){
		a[i] = j;
		if(i==n){
			if(kt())
				ans.push_back(a);
		} else
			tryAt(i + 1);
	}
}

int main() {
	cin >> n >> k;
	tryAt(1);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size();i++){
		for (int j = 1; j <= n;j++){
			if(ans[i][j]==0)
				cout << "A";
			else
				cout << "B";
		}
		cout << endl;
	}
		return 0;
}

