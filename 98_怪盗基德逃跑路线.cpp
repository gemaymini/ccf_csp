#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int dp[N];
int main(){
	int k;
	cin>>k;
	while(k--){
		int n;
		cin>>n;
		
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		
		for(int i=0;i<n;i++)dp[i]=1;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(a[j]<a[i]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		
		int res=0;
		
		for(int i=0;i<n;i++)res=max(res,dp[i]);
		
		
		for(int i=0;i<n;i++)dp[i]=1;

		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(a[j]>a[i]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		
		for(int i=0;i<n;i++)res=max(res,dp[i]);
		
		cout<<res<<endl;
	}
	
}
