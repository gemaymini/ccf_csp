#include<bits/stdc++.h>
using namespace std;
const int N=20;
int a[N][N];
int dp[N],b[N];
vector<vector<pair<int,int>>>v(N);
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--){
			for(int k=1;k<=m;k++){
				if(j>=k){
					if(dp[j]<dp[j-k]+a[i][k]){
						dp[j]=dp[j-k]+a[i][k];
						v[j]=v[j-k];
						v[j].push_back({i,k});
					}
				
				}					
				
			}
		}
	}
	
	
	cout<<dp[m]<<endl;
	
	for(auto e:v[m]){
		b[e.first]=e.second;
	}
	for(int i=1;i<=n;i++){
		cout<<i<<" "<<b[i]<<endl;
	}
}
