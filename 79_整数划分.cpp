#include<bits/stdc++.h>
using namespace std;
int dp[1005];
//dp[i][j]=dp[i-1][j]+dp[i-1][j-i]+dp[i-1][j-2i]...
//dp[i][j-i]=dp[i-1][j-i]+dp[i-1][j-2i]...
//dp[i][j]=dp[i-1][j-i]+dp[i][j-i]
const int mod =1e9+7;

int main(){
    int n;
    cin>>n;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(j>=i) dp[j]=(dp[j]+dp[j-i])%mod;
        }
    }
    cout<<dp[n];
}