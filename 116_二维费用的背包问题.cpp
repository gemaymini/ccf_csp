#include<bits/stdc++.h>
using namespace std;
const int N=1050,V=105,M=105;
int dp[N][V][M];//前i个物品,容量为v，重量为m的最大价值
//取i，dp[i-1][v-vi][m-mi]+wi
//不取i,dp[i-1][v][m]
int main(){
	int n,v,m;
	cin>>n>>v>>m;
	for(int i=1;i<=n;i++){
		int vi,mi,wi;
		cin>>vi>>mi>>wi;
		for(int j=0;j<=v;j++){
			for(int k=0;k<=m;k++){
				dp[i][j][k]=dp[i-1][j][k];
				if(j>=vi&&k>=mi)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-vi][k-mi]+wi);
			}
		}
	}

	cout<<dp[n-1][v][m];
}
