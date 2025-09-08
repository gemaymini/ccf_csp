#include<bits/stdc++.h>
using namespace std;

const int N = 15;
int a[N][N];
int dp[2 * N][N][N];

int main() {
	int n;
	cin >> n;
	int r, c, w;
	while (cin >> r >> c >> w, r || c || w) {
		a[r - 1][c - 1] = w;
	}
	// for(int i1=0;i1<n;i1++){
	//     for(int i2=0;i2<n;i2++){
	//         cout<<a[i1][i2]<<" ";
	//     }
	//     cout<<endl;
	// }


	for (int k = 0; k < 2 * n; k++) {
		for (int i1 = 0; i1 < n; i1++) {
			for (int i2 = 0; i2 < n; i2++) {
				int j1 = k - i1, j2 = k - i2;
				if (j1 >= 0 && j1 < n && j2 >= 0 && j2 < n) {
					if (i1 == 0 && i2 == 0 && k == 0) {
						dp[k][i1][i2] = a[i1][j1];
						continue;
					}
					int t = a[i1][j1];
					if (i1 != i2) {
						t += a[i2][j2];
					}
					if (i1 > 0 && i2 > 0) {
						dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][i1 - 1][i2 - 1] + t);
					}
					if (i1 > 0 && j2 > 0) {
						dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][i1 - 1][i2] + t);
					}
					if (j1 > 0 && i2 > 0) {
						dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][i1][i2 - 1] + t);
					}
					if (j1 > 0 && j2 > 0) {
						dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][i1][i2] + t);
					}
				}

			}


		}
	}
	// for(int i=0;i<2*n;i++){
	//        cout<<dp[i][n-1][n-1]<<endl;
	// }
	cout << dp[2 * n - 2][n - 1][n - 1];
}
