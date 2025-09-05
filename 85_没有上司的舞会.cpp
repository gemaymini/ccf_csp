#include<bits/stdc++.h>
using namespace std;
const int N=6005;
int a[N];
int n;
int  h[N],e[N],ne[N],idx;

void add(int k, int l){
    e[idx]=l;
    ne[idx]=h[k];
    h[k]=idx++;
}
int dp[N][2];
void dfs(int x){
    if(h[x]==-1){
        dp[x][1]=a[x];
        dp[x][0]=0;
        return;
    }
    dp[x][1]=a[x];
    for(int i=h[x];i!=-1;i=ne[i]){
        int j=e[i];
        dfs(j);
        dp[x][0]+=max(dp[j][0],dp[j][1]);
        dp[x][1]+=dp[j][0];
    }

}
int cnt[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(h,-1,sizeof h);
    for(int i=1;i<n;i++){
        int l,k;
        cin>>l>>k;
        add(k,l);
        cnt[l]++;
    }
    int t=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]==0){
            t=i;
            break;
        }
    }
    dfs(t);
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<dp[i][0]<< " "<<dp[i][1]<<endl;
    // }
    cout<<max(dp[t][1],dp[t][0]);
}