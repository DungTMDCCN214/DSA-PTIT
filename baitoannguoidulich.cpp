#include<bits/stdc++.h>


using namespace std;

int n, c[105][105], x[100];
int visited[105];
int d=0, ans=INT_MAX;
int cmin=INT_MAX;

void nhap() {
    cin >>n;
    for(int i=1; i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
            if(c[i][j] != 0){
                cmin = min(cmin,c[i][j]);
            }
        }
    }
    memset(visited,0,sizeof(visited));
}
void Try(int i){
    for(int j=1;j<=n;j++){
        if(visited[j]==0){
            visited[j]=1;
            x[i]=j;
            d+=c[x[i-1]][x[i]];
            if(i==n){
                ans=min(ans,d+c[x[n]][1]);
            } else if(d+ ( n-i+1) * cmin < ans) {
                Try(i+1);
            }
            // Danh gia can duoi
            visited[j]=0;
            d-=c[x[i-1]][x[i]];
        }
    }
}
void Try(int i){
    for(int i=1;i<n;i++){
        if(visited[i]==0){
            visited[i]=1;
            x[i]=j;
            d+=c[x[i-1]][x[i]];
        }
    }
}
int main() {
    nhap();
    x[1]=1;
    visited[1]=1;
    Try(2);
    cout<<ans<<endl;
}