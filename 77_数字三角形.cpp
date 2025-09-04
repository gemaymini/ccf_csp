#include<bits/stdc++.h>
using namespace std;
int a[505][505];
int dp[505][505];
int main(){
    memset(dp,-0x3f,sizeof dp);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    dp[0][0]=0,dp[0][1]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i-1][j-1]+a[i][j]);
        }
    }
    int res=INT_MIN;
    for(int i=1;i<=n;i++){
        res=max(dp[n][i],res);
    }
    cout<<res;
}