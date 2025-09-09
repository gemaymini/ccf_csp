#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int dp[N][105][2];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(dp,-0x3f,sizeof dp);
	dp[0][0][0]=0;
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			dp[i][j][0]=dp[i-1][j][0];
			if(j>0)dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-1][1]+a[i]);
			dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j][0]-a[i]);
		}
	}
	for(int i=0;i<=k;i++)res=max(res,dp[n][i][0]);
	cout<<res<<endl;
}
