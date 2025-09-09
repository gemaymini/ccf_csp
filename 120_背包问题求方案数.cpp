#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005,mod=1e9+7;
int n,m;
int dp[N],cnt[N];

signed main(){
	cin>>n>>m;
	memset(dp,-0x3f,sizeof dp);
	dp[0]=0;
	for(int i=0;i<=m;i++)
		cnt[i]=1;
	for(int i=0;i<n;i++){
		int v,w;
		cin>>v>>w;
		for(int j=m;j>=v;j--){
			if(dp[j]<dp[j-v]+w){
				cnt[j]=cnt[j-v];
				dp[j]=dp[j-v]+w;
			}else if(dp[j]==dp[j-v]+w){
				cnt[j]+=cnt[j-v]%mod;
			}
		}
	}
	int res=0,t=0;
	for(int i=0;i<=m;i++)t=max(t,dp[i]);
	for(int i=0;i<=m;i++)if(dp[i]==t)res+=cnt[i]%mod;
	
	cout<<res;
}
