#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int v[N],w[N],dp[N][N];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>w[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<=m;j++){
			dp[i][j]=dp[i+1][j];
			if(j>=v[i])dp[i][j]=max(dp[i][j],dp[i+1][j-v[i]]+w[i]);
		}
	}
	int j=m;
	for(int i=1;i<=n;i++){
		if(j>=v[i]&&dp[i][j]==dp[i+1][j-v[i]]+w[i]){
			cout<<i<<' ';
			j-=v[i];
		}
	}
}
