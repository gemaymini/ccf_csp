#include<bits/stdc++.h>
using namespace std;
const int M=65,N=32050;
int dp[M][N];
int v[N],w[N],h[N],e[N],idx,ne[N];
int n,m;

void add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
void dfs(int u){
	for(int i=h[u];i!=-1;i=ne[i]){
		int son=e[i];
		dfs(son);
		for(int j=n-v[u];j>=0;j--){
			for(int k=0;k<=j;k++){
					dp[u][j]=max(dp[u][j],dp[son][k]+dp[u][j-k]);
				}
			}
		}


	for(int i=n;i>=v[u];i--){
		dp[u][i]=dp[u][i-v[u]]+w[u];
	}
	for(int i=0;i<v[u];i++){
		dp[u][i]=0;
	}
}


int main(){
	memset(h,-1,sizeof h);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int q;
		cin>>v[i]>>w[i]>>q;
		w[i]*=v[i];
		add(q,i);
		
	}
	dfs(0);
	cout<<dp[0][n];
}
