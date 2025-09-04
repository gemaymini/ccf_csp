#include<bits/stdc++.h>
using namespace std;
int dp[105];
int main(){
    int N,V;
    cin>>N>>V;
    for(int i=1;i<=N;i++){
        vector<pair<int,int>>item;
        
        int n;
        cin>>n;

        for(int j=1;j<=n;j++){
            int v,w;
            cin>>v>>w;
            item.push_back({v,w});
        }

        for(int j=V;j>=0;j--){
            for(auto &[v,w]:item){
                if(j>=v)dp[j]=max(dp[j],dp[j-v]+w);
            }
        }
    }
    cout<<dp[V];
}   