#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[1005][1005];
int main(){
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;
    s1=" "+s1;
    s2=" "+s2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i]==s2[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m];
}