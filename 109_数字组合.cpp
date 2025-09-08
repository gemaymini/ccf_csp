#include<bits/stdc++.h>
using namespace std;
const int N=105,M=1e4+5;
int a[N];

int dp[N][M];//前n个数字中，和为m的方案数
//dp[i][j] 选i, dp[i][j]+=dp[i-1][j-a[i]]
//         不选i, dp[i][j]+=dp[i-1][j] 
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]+=dp[i-1][j];
			if(j>=a[i])dp[i][j]+=dp[i-1][j-a[i]];
		}
	}
	cout<<dp[n][m];
}
