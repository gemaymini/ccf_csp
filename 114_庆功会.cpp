#include<bits/stdc++.h>
using namespace std;
const int N=6050;
int f[N],g[N],q[N];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int v,w,s;
		cin>>v>>w>>s;
		memcpy(f,g,sizeof g);
		for(int j=0;j<v;j++){
			int hh=0,tt=-1;
			for(int k=j;k<=m;k+=v){
				if(hh<=tt&&q[hh]<k-s*v)hh++;
				if(hh<=tt)g[k]=max(g[k],f[q[hh]]+(k-q[hh])/v*w);
				while(hh<=tt&&f[q[tt]]-(q[tt]-j)/v*w<=f[k]-(k-j)/v*w)tt--;
				q[++tt]=k;
			}
		}
	}
	cout<<g[m];
}
