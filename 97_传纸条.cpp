#include<bits/stdc++.h>
using namespace std;
const int N=55;
int a[N][N];
int dp[2*N][N][N];


int main(){
	int n,m;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	
	for(int k=1;k<n+m;k++)
	{
		for(int i1=0;i1<m;i1++){
			for(int i2=0;i2<m;i2++){
				int j1=k-i1,j2=k-i2;
				if(j1>=0&&j1<n&&j2>=0&&j2<n){
					int t=a[i1][j1]+a[i2][j2];
					if(i1==i2){
						t/=2;
					}
					dp[k][i1][i2]=max(dp[k][i1][i2],dp[k-1][i1-1][i2-1]+t);
					dp[k][i1][i2]=max(dp[k][i1][i2],dp[k-1][i1][i2-1]+t);
					dp[k][i1][i2]=max(dp[k][i1][i2],dp[k-1][i1-1][i2]+t);
					dp[k][i1][i2]=max(dp[k][i1][i2],dp[k-1][i1][i2]+t);
				}
			}
		}
	}
	cout<<dp[n+m-2][m-1][m-1];
}
