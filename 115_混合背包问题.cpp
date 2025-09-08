#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int dp[N][N];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int v,w,s;
		cin>>v>>w>>s;
		if(s==-1){
			for(int j=m;j>=0;j--){
				dp[i][j]=dp[i-1][j];
				if(j>=v)dp[i][j]=max(dp[i][j],dp[i-1][j-v]+w);
			}
		}
		else if(s==0){
			for(int j=0;j<=m;j++){
				dp[i][j]=dp[i-1][j];
				if(j>=v)dp[i][j]=max(dp[i][j],dp[i][j-v]+w);
			}
		}
		else {
			int t=1;
			vector<pair<int,int>>q;
			while(s>=t){
				q.push_back({v*t,w*t});
				s-=t;
				t*=2;
			}
			if(s>0){
				q.push_back({v*s,w*s});
			}
			vector<int>g(m+1,0),f(m+1,0);
			for(int j=0;j<=m;j++){
				f[j]=dp[i-1][j];
			}
			for(auto& [tv,tw]:q){
				for(int j=m;j>=0;j--){
					g[j]=f[j];
					if(j>=tv)g[j]=max(g[j],f[j-tv]+tw);
				}
				f=g;
			}
			for(int j=0;j<=m;j++){
				dp[i][j]=g[j];
			}
		}
	} 
	cout<<dp[n][m];
}
