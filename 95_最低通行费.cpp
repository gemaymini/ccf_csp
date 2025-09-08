#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N][N];
int dp[N][N];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    memset(dp,0x3f3f3f,sizeof dp);
    dp[0][0]=a[0][0];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(j>0)dp[i][j]=min(dp[i][j],dp[i][j-1]+a[i][j]);
            if(i>0)dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i][j]);
        }
    cout<<dp[n-1][n-1];
    
}