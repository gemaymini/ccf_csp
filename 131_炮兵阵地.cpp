#include<bits/stdc++.h>
using namespace std;
const int N=105,M=1<<10;
int g[N];
vector<int>q;
int dp[2][M][M];
bool check(int i){
	if(i&(i>>1)||i&(i>>2))return false;
	else return true;
}
int cnt(int i){
	int cnt=0;
	while(i){
		if(i&1)cnt++;
		i/=2;
	}
	return cnt;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=m-1;j>=0;j--){
			char c;cin>>c;
			if(c=='P')
				g[i]+=1<<j;
		}
	}
		
	for(int i=0;i<1<<m;i++){
		if(check(i))q.push_back(i);

	}

	for(int i=1;i<=n;i++){
		for(int j=0;j<q.size();j++){
			for(int k=0;k<q.size();k++){
				for(int u=0;u<q.size();u++){
					int a=q[j],b=q[k],c=q[u];
//					cout<<a<<" "<<b<<" "<<c<<endl;
					if((a&b)||(b&c)||(a&c))continue;
					if(((g[i]&b)!=b)||((g[i-1]&a)!=a))continue;
//					cout<<b<<" "<<cnt(b)<<endl;
					dp[i&1][j][k]=max(dp[i&1][j][k],dp[(i-1)&1][u][j]+cnt(b));
//					cout<<dp[i&1][j][k]<<endl;
				}
			}
		}
	}

	int res=0;
	for(int j=0;j<q.size();j++){
		for(int k=0;k<q.size();k++){
			res=max(res,dp[n&1][j][k]);
		}
	}		
	cout<<res;
}
