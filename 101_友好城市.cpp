#include<bits/stdc++.h>
using namespace std;
const int N=5005;
struct node{
	int l,r;
	bool operator<(const node& e)const{
		return l<e.l;
	}
};
int f[N];
node p[N];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int v,u;cin>>v>>u;
		p[i]={v,u};
	}
	sort(p,p+n);
	for(int i=0;i<n;i++){
		f[i]=1;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(p[i].r>p[j].r)f[i]=max(f[i],f[j]+1);
		}	
	}
	int res=0;
	for(int i=0;i<n;i++){
		res=max(res,f[i]);

	}
	cout<<res;
}
