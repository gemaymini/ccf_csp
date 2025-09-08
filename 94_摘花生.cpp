#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N][N];
int dp[N][N];
int main(){
    int t;cin>>t;
    while(t--){
        memset(dp,0,sizeof dp);
        memset(a,0,sizeof a);
        int r,c;cin>>r>>c;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>a[i][j];
            }
        }
        dp[0][0]=a[0][0];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(j>0){
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i][j]);
                }
                if(i>0){
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i][j]);
                }
                
            }
        }
        cout<<dp[r-1][c-1]<<endl;

    }
    
}