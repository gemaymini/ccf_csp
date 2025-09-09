#include<bits/stdc++.h>
using namespace std;
const int N=32050,M=65;
int n,m,p;
int h[M],idx,e[M],ne[M],c[M];
int dp[N];
int v[M],w[M];
bool root[M];
void add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
	c[a]++;
}


int main(){
	cin>>n>>m;
	memset(h,-1,sizeof h);
	for(int i=1;i<=m;i++){
		cin>>v[i]>>w[i]>>p;
		w[i]*=v[i];
		if(p!=0){
			add(p,i);
			root[i]=true;
		}
	}
	
	for(int i=1;i<=m;i++){
		if(!root[i]){
			vector<pair<int,int>>q;
			int s1,s2;
			q.push_back({v[i],w[i]});
			if(c[i]>=1){
				s1=h[i];
				int t=e[s1];
				q.push_back({v[i]+v[t],w[i]+w[t]});
			}
			if(c[i]==2){
				s2=ne[s1];
				int t=e[s2];
				q.push_back({v[i]+v[t],w[i]+w[t]});
				q.push_back({v[i]+v[t]+v[e[s1]],w[i]+w[t]+w[e[s1]]});
			}
			for(int j=n;j>=0;j--){
				for(auto& e:q){
					if(j>=e.first)dp[j]=max(dp[j],dp[j-e.first]+e.second);
				}
			}
//			for(auto& e:q){
//				cout<<e.first<<" "<<e.second<<endl;
//			}
//			cout<<endl;
		}

	}
	cout<<dp[n];
}
