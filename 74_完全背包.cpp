#include<bits/stdc++.h>
using namespace std;
int w[1010],v[1010],dp[1010];
int main(){
    int N,V;
    cin>>N>>V;
    for(int i=1;i<=N;i++){  
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=v[i];j<=V;j++){
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[V];
}