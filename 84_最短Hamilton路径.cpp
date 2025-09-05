#include<bits/stdc++.h>
using namespace std;
const int N=25;
int d[N][N];
int dp[N][1<<20];
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
        }
    }
    memset(dp,0x3f,sizeof dp);

    dp[0][1]=0;
    for(int i=1;i<1<<n;i++){
        if(i&1){
        for(int j=0;j<n;j++){
            if(i>>j&1){
                for(int k=0;k<n;k++){
                    if((k!=j)&&((i>>k)&1)){
                        dp[j][i]=min(dp[j][i],dp[k][i-(1<<j)]+d[k][j]);
                    }
                }
            }
        }}
    }
    cout<<dp[n-1][(1<<n)-1];

}