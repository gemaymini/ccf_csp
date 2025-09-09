#include<bits/stdc++.h>
using namespace std;
const int N=1050,V=105,M=105;
int dp[V][M];//前i个物品,容量为v，重量为m的最大价值
//取i，dp[i-1][v-vi][m-mi]+wi
//不取i,dp[i-1][v][m]
int main(){
	int n,v,m;
	cin>>n>>v>>m;
	for(int i=1;i<=n;i++){
		int vi,mi,wi;
		cin>>vi>>mi>>wi;
		for(int j=v;j>=0;j--){
			for(int k=m;k>=0;k--){
				if(j>=vi&&k>=mi)dp[j][k]=max(dp[j][k],dp[j-vi][k-mi]+wi);
			}
		}
	}

	cout<<dp[v][m];
}
