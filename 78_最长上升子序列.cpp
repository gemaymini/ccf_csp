#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int> a(N,0),dp(N,0);

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+1);
        }        
    }
    int res=0;
    for(int i=1;i<=n;i++){
        res=max(res,dp[i]);
        // cout<<i<< " "<<dp[i]<<endl;
    }
    cout<<res+1;
}