#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=12,K=110;
bool vis[1<<N];
int dp[N][K][1<<N];
int c1[1<<N];
int main(){
	int n,k;
	cin>>n>>k;
	memset(vis,true,sizeof vis);
	
	for(int st=0;st<1<<n;st++){
		int t=st;
		int cnt=0;
		int c=0;
		while(t){
			if(t%2==0){
				if(cnt>1){
					vis[st]=false;	
				}
				cnt=0;
			}else{
				cnt++;
				c++;
			}
			t/=2;
		}
		if(cnt>1){
			vis[st]=false;	
		}
		c1[st]=c;

	}

	dp[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int st=0;st<1<<n;st++){
			if(vis[st]){//同一行不能连续两个1
				for(int lst=0;lst<1<<n;lst++){
					if(((lst&st)==0)&&vis[lst|st]){
						for(int t=c1[st];t<=k;t++){
							if(t>=c1[lst])dp[i+1][t][lst]+=dp[i][t-c1[lst]][st];
						}
					}
				}
			}
		}
	}
	int res=0;
	for(int i=0;i<1<<n;i++)res+=dp[n][k][i];
	cout<<res;
}
