#include<bits/stdc++.h>
using namespace std;
const int N=110;
int v[N],w[N];
int n,m,root;
int h[N],e[N],ne[N],idx;
int d[N][N];
void add(int x,int y){
	e[idx]=y;
	ne[idx]=h[x];
	h[x]=idx++;
}

void dfs(int u){
	for(int i=h[u];i!=-1;i=ne[i]){
		int son=e[i];
		dfs(son);
		for(int j=m-v[u];j>=0;j--){
			for(int k=0;k<=j;k++){
				d[u][j]=max(d[u][j],d[u][j-k]+d[son][k]);
			}
		}
	}
	for(int i=m;i>=v[u];i--)d[u][i]=d[u][i-v[u]]+w[u];
	for(int i=0;i<v[u];i++)d[u][i]=0;
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
	cout<<d[root][m];
}
