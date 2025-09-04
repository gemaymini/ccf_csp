#include<bits/stdc++.h>
using namespace std;
int v[1010],w[1010];
int dp[1010];
int main(){
    int N,V;
    cin>>N>>V;
    for(int i=1;i<=N;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=V;j>=0;j--){
            if(j>=v[i])dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[V];
}