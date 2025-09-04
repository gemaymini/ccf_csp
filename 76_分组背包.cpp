#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int main(){
    int N,V;
    cin>>N>>V;
    for(int i=1;i<=N;i++){
        int n;cin>>n;

        for(int k=0;k<=V;k++){
            dp[i][k] = dp[i-1][k];
        }
        
        for(int j=1;j<=n;j++){
            int v,w;
            cin>>v>>w;
            for(int k=V;k>=v;k--){
                dp[i][k]=max(dp[i][k],dp[i-1][k-v]+w);
            }
        }
    }
    cout<<dp[N][V];
}