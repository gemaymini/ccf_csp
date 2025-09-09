#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
int v[N],w[N];
int h[N],e[N],ne[N],idx;
int dp[N][N];
int root;

void add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

void dfs(int u)
{
	for(int i=h[u];i!=-1;i=ne[i]){
		int son=e[i];
		dfs(son);
		for(int j=m-v[u];j>=0;j--){
			for(int k=j;k>=0;k--){
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[son][k]);
			}
		}
	}
	for(int i=m;i>=v[u];i--)dp[u][i]=dp[u][i-v[u]]+w[u];
	for(int i=0;i<v[u];i++)dp[u][i]=0;
}
int main(){
	cin>>n>>m;
	memset(h,-1,sizeof h);
	for(int i=1;i<=n;i++){
		int p;
		cin>>v[i]>>w[i]>>p;
		if(p==-1){
			root=i;
		}else{
			add(p,i);
		}
	}
	dfs(root);
	cout<<dp[root][m];
}
