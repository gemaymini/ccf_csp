#include<bits/stdc++.h>
using namespace std;
const int N=105;
struct node{
	int s,e,l;
	bool operator<(const node& e)const{
		return s*e.l<e.s*l;
	}
}stone[N];
int dp[N][10005];
void func(int c){
	int n;cin>>n;
	int m=0;
	memset(dp,-0x3f,sizeof dp);
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		int s,e,l;
		cin>>s>>e>>l;
		stone[i]={s,e,l};
		m+=s;
	}
	sort(stone+1,stone+n+1);
	for(int i=1;i<=n;i++){
		int s=stone[i].s,e=stone[i].e,l=stone[i].l;
		for(int j=m;j>=0;j--){
			dp[i][j]=dp[i-1][j];
			if(j>=s)dp[i][j]=max(dp[i][j],dp[i-1][j-s]+e-(j-s)*l);
		}
	}
	int res=0;
	for(int i=1;i<=m;i++){
		res=max(res,dp[n][i]);
	}
	cout<<"Case "<<"#"<<c<<": "<<res<<endl;
}

int main(){
	int t;cin>>t;
	int c=1;
	while(t--){
		func(c);
		c++;
	}
}
