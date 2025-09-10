#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=15,mod=1e8;

int a[N];
bool vis[1<<N];
int dp[N][1<<N];
signed main(){
	int n,m;
	memset(vis,true,sizeof vis);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int t;cin>>t;
			a[j]*=2;
			a[j]+=t;
		}		
		
	}
//	cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
	for(int i=0;i<1<<n;i++){
		int t=i,cnt=0;
		while(t){
			if(t%2==0){
				if(cnt>1){
					vis[i]=false;	
				}
				cnt=0;
			}else{
				cnt++;
			}
			t/=2;
		}
		if(cnt>1){
			vis[i]=false;	
		}
	}
	dp[0][0]=1;
	
	for(int i=0;i<m;i++)
	{
		for(int st=0;st<1<<n;st++){
			if(((a[i]&st)==st)&&vis[st]){
				for(int lst=0;lst<1<<n;lst++){
					if(((a[i+1]&lst)==lst)&&vis[lst]&&((lst&st)==0)){
						dp[i+1][lst]=(dp[i][st]+dp[i+1][lst])%mod;
					}
				}
			}
		}
	}
	int res=0;
	for(int i=0;i<1<<n;i++){
		res=(res+dp[m][i])%mod;
	}
//	for(int j=0;j<=m;j++){
//		for(int i=0;i<1<<n;i++){
//			cout<<dp[j][i]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<res%mod;
}
