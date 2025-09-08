#include<bits/stdc++.h>
using namespace std;
const int N = 1005, M = 505, K = 105;
int v[K], w[K];
int dp[N][M];//使用n个球,剩余m体力时的最大精灵数
//catch k 精灵  dp[k-1][n-v[k]]+1
// donot catch k 精灵
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	
	for (int i = 1; i <= k; i++) {
		cin >> v[i] >> w[i];
	}
	
	for (int i = 1; i <= k; i++) {
		for (int j = n; j >= 0; j--) {
			for (int t = 1; t <=m ; t++) {
				if (j >=v[i] && t+w[i]<=m)dp[j][t] = max(dp[j][t], dp[j - v[i]][t+w[i]] + 1);
			}
			
		}
	}
	int c=0,r=0;
	for(int i=1;i<=m;i++){
		if(c<dp[n][i]){
			c=dp[n][i];
			r=i;
		}
		else if(c==dp[n][i]){
			if(r<i){
				r=i;
			}
		}	
	}
	cout<<c<<" "<<r;
}
