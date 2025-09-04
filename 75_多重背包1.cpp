#include<bits/stdc++.h>
using namespace std;
vector<int>v,w;
int n;
int dp[105];
int main(){
    int N,V;
    cin>>N>>V;
    for(int i=1;i<=N;i++){

        int wi,si,vi;
        cin>>vi>>wi>>si;
        int t=1;
        while(si>=t){
            v.push_back(vi*t);
            w.push_back(wi*t);
            si-=t;
            t*=2;

        }
        if(si>0){
            v.push_back(vi*si);
            w.push_back(wi*si);
        }
    }
    for(int i=0;i<v.size();i++){
        for(int j=V;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[V];
}