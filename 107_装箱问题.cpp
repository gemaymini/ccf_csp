#include<bits/stdc++.h>
using namespace std;
const int MV=2e4+5,N=35;
int a[N];
int dp[MV];
//前i个物品，剩下的最小空间 min
//包含i dp[i-1]-a[i]
//不包含i min(dp[k]) 
int main(){
	int V,n;
	cin>>V>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=V;j>=a[i];j--){
			dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
		}
	}
	cout<<V-dp[V];
}
