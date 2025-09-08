#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int h[N];
int dp[N][2];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=1;dp[i][1]=1;
		for(int j=1;j<i;j++){
			if(h[i]>h[j]) dp[i][0]=max(dp[i][0],dp[j][0]+1);
			if(h[i]<h[j]) dp[i][1]=max(dp[i][1],max(dp[j][0],dp[j][1])+1);
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		
		res=max(res,max(dp[i][1],dp[i][0]));
	}
	cout<<n-res;
	
	
}
