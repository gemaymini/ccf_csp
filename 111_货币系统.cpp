#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20,M=3010;
int a[N];
int dp[M];//前n种货币组成M的方案数
//dp[i][j]      = dp[i-1][j] + dp[i-1][j-a[i]] + ... + dp[i-1][j-k*a[i]]
//dp[i][j-a[i]] =            + dp[i-1 [j-a[i]] + ... + dp[i-1][j-k*a[i]]

signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(j>=a[i])
				dp[j]+=dp[j-a[i]];
		}
	}	
	cout<<dp[m];
}
