#include<bits/stdc++.h>
using namespace std;
const int N = 1005, M = 505, K = 105;
int v[K], w[K];
int dp[K][N][M];//前k个精灵，使用n个球,剩余m体力时的最大精灵数
//catch k 精灵  dp[k-1][n-v[k]]+1
// donot catch k 精灵
int main() {
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= k; i++) {
		cin >> v[i] >> w[i];
	}
	dp[0][0][m] = 0;

	for (int i = 1; i <= k; i++) {
		for (int j = n; j >= 0; j--) {
			for (int t = 0; t <=m ; t++) {
				if (j >=v[i] && t+w[i]<=m)dp[i][j][t] = max(dp[i][j][t], dp[i - 1][j - v[i]][t+w[i]] + 1);
				dp[i][j][t] = max(dp[i][j][t], dp[i - 1][j][t]);
			}

		}
	}
	int c=0,r=0;
	for(int i=1;i<=m;i++){
		if(c<dp[k][n][i]){
			c=dp[k][n][i];
			r=i;
		}
		else if(c==dp[k][n][i]){
			if(r<i){
				r=i;
			}
		}	
	}
	cout<<c<<" "<<r;
}
