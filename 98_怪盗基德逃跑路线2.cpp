#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n;
int a[N],d[N],idx;

int search1(int x){
	if(idx==0){
		return 0;
	}
	int l=0,r=idx+1;
	while(l+1!=r){
		int mid=(l+r)>>1;
		if(d[mid]>=x) r=mid;
		else l=mid;
	}
	return l;
}

void func(){
	idx=0;
	for(int i=1;i<=n;i++){
		int dx=search1(a[i]);
		if(dx==idx){
			idx++;
		}
		d[dx+1]=a[i];
	}
	int res=idx;
	
	idx=0;
	for(int i=n;i>=1;i--){
		int dx=search1(a[i]);
		if(dx==idx){
			idx++;
		}
		d[dx+1]=a[i];
	}
	res=max(res,idx);
	cout<<res<<endl;
}

int main(){
	int k;
	cin>>k;
	while(k--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}		
		func();
	}
}
