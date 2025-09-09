#include<bits/stdc++.h>
using namespace std;
const int M=30,N=3e4+5;
int v[M],p[M];
int dp[N];
int main(){
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>v[i]>>p[i];
		p[i]=v[i]*p[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=N;j>=0;j--){
			if(j>=v[i])dp[j]=max(dp[j],dp[j-v[i]]+p[i]);
		}
	}
	cout<<dp[n];
	
}
