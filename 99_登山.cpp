#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N];
int dp[N], dq[N];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {

		dp[i] = 1;
		dq[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = n-1; i >=0; i--) {
		for (int j = n-1; j >i; j--) {
			if (a[j] < a[i]) {
				dq[i] = max(dq[i], dq[j] + 1);
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
//		cout<<dp[i]<< " "<<dq[i]<<endl;
		res = max(res, dp[i] + dq[i]);
	}
	cout << res - 1;
}


