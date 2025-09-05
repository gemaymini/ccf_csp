#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int main(){
    int n,m;
    string a,b;

    cin>>n>>a;
    cin>>m>>b;
    a=" "+a;
    b=" "+b;
    for(int i=0;i<=n;i++)dp[i][0]=i;
    for(int j=0;j<=m;j++)dp[0][j]=j;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int c1,c2,c3;
            if(a[i]==b[j]){
                c1=dp[i-1][j-1];
            }else{
                c1=dp[i-1][j-1]+1;
            }
            c2=dp[i-1][j]+1;
            c3=dp[i][j-1]+1;
            dp[i][j]=min(c1,min(c2,c3));

        }
    }
    cout<<dp[n][m];
}