#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int dp[N][2];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
			dp[i][1]=dp[i-1][0]+a[i];
		}
		cout<<max(dp[n][0],dp[n][1])<<endl;
	}
}
