#include<bits/stdc++.h>
using namespace std;

int n,t,a[105];
int dp[105][25050];

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=25000;j++){
				dp[i][j]=dp[i-1][j];
				if(j>=a[i])dp[i][j]+=dp[i][j-a[i]];
			}	
		}
		int ans=n;
		
		for(int i=1;i<=n;i++){
			if(dp[i-1][a[i]]>0){
				ans--;
			}
		}
		cout<<ans<<endl;
	}
}
