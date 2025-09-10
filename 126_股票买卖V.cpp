#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int dp[N][3];

//持仓=持仓+空仓买入
//空仓=空仓+冷静期
//冷静期=持仓卖出
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(dp,-0x3f,sizeof dp);
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][2]);
		dp[i][1]=max(dp[i-1][1],dp[i-1][0]-a[i]);
		dp[i][2]=dp[i-1][1]+a[i];
//		cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
	}
	cout<<max(dp[n][0],dp[n][2]);
}
