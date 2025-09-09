#include<bits/stdc++.h>
using namespace std;
const int K=1005,M=100;

int dp[K][M][M];
//前i个罐，有j氧气，有k氮气的最小重量
//取i，dp[i-1][j-a][k-b]+c;
//不取i,dp[i-1][j][k];


int main(){
	int m,n;
	cin>>m>>n;
	int t;
	cin>>t;
	memset(dp,0x3f,sizeof dp);
	
	dp[0][0][0]=0;
	for(int i=1;i<=t;i++){
		int a,b,c;
		cin>>a>>b>>c;
		for(int j=m;j>=0;j--){
			for(int k=n;k>=0;k--){
				dp[i][j][k]=dp[i-1][j][k];
				int tj,tk;
				if(j>=a)tj=j-a;
				else tj=0;
				if(k>=b)tk=k-b;
				else tk=0;
				dp[i][j][k]=min(dp[i][j][k],dp[i-1][tj][tk]+c);
				
			}
		}		
	}
	
	cout<<dp[t][m][n];
}
