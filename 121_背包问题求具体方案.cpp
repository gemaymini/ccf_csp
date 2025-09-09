#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int dp[N];
vector<vector<int>>q;
bool big(vector<int>q1,vector<int>q2,int i,bool flag=false){
	if(!flag)q2.push_back(i);
	int t=min(q1.size(),q2.size());
	for(int i=0;i<t;i++){
		if(q1[i]!=q2[i]) return q1[i]>q2[i];
	}
	return q1.size()>q2.size();
}
int main(){
	int n,m;
	cin>>n>>m;
	q.resize(m+1);
	for(int i=1;i<=n;i++){
		int v,w;
		cin>>v>>w;
		for(int j=m;j>=v;j--){
			if(dp[j]<dp[j-v]+w){
				dp[j]=dp[j-v]+w;
				q[j]=q[j-v];
				q[j].push_back(i);
			}else if(dp[j]==dp[j-v]+w){
				if(big(q[j],q[j-v],i)){
					q[j]=q[j-v];
					q[j].push_back(i);
				}
			}
		}
	}	

	for(auto e:q[m]){
		cout<<e<<" ";
	}
	cout<<endl;
}
