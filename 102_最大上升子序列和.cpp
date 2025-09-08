#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N];
int s[N];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)s[i]=a[i];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]>a[j])s[i]=max(s[i],s[j]+a[i]);
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)res=max(res,s[i]);
	cout<<res;
}
