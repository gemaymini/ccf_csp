#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int dp[5][N];//前i种书,n元钱有几种方法
//不买i，dp[i][n]+=dp[i-1][N];
//买i, dp[i][n]+=dp[i-1][n-k*a[i]]
//完全背包优化
//dp[i][n]=dp[i][n-a[i]]+dp[i-1][n];
int main(){
	int n;
	cin>>n;
	if(n%10!=0){
		cout<<0;
		return 0;
	}
	int* a=new int[5]{0,10,20,50,100};
	dp[0][0]=1;
	for(int i=1;i<=4;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k*a[i]<=j;k++)
				dp[i][j]+=dp[i-1][j-k*a[i]];
		}
	}
	cout<<dp[4][n];
}
