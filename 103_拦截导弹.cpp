#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N];
int d[N];
int cnt;
int f[N];
int main(){
	int n=1;
	while(cin>>a[n])n++;
	int ans=0;
	n--;
	for(int i=1;i<=n;i++){
		d[i]=1;
		for(int j=1;j<i;j++){
			if(a[i]<=a[j])d[i]=max(d[i],d[j]+1);
		}
		ans=max(ans,d[i]);

		int t=lower_bound(f,f+cnt,a[i])-f;
		if(t==cnt){
			f[cnt++]=a[i];
		}else{
			f[t]=a[i];
		}
	}
	cout<<ans<<endl;
	cout<<cnt;
	
	
	
}
