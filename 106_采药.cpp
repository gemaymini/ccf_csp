#include<bits/stdc++.h>
using namespace std;
const int T=1005,M=105;
int t,m;
int tim[M],weight[M];
int dp[T];
int main(){
	cin>>t>>m;
	for(int i=0;i<m;i++){
		cin>>tim[i]>>weight[i];
	}
	for(int i=0;i<m;i++){
		for(int j=t;j>0;j--){
			if(j>=tim[i])dp[j]=max(dp[j],dp[j-tim[i]]+weight[i]);
		}
	}
	cout<<dp[t];
}
