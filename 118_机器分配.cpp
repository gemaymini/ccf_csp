#include<bits/stdc++.h>
using namespace std;
const int N=20,M=20;
int a[N][M];
//c_N^(M+1)
//c_17_^11
//c_17^6
//
int main(){

	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	
	vector<int>v(m+1+n,0);
	for(int i=0;i<n+1;i++)
		v[i]=1;
	int res=0;
	v[m+n+1]=1;
	do{
		for(auto e:v){
			cout<<e<<" ";
		}
		cout<<endl;
		int sum=0;
		int idx=1,cnt=0;
		for(int i=0;i<n;i++){
			if(v[i]==0){
				cnt++;	
			}else if(v[i]==-1){
				continue;
			}else{
				if(cnt!=0)
					sum+=a[idx][cnt];
//				cout<<idx<<" "<<cnt<<endl;
//				cout<<a[idx][cnt]<<endl;
				cnt=0;
				idx++;
			}
		}
		res=max(res,sum);
	}while(prev_permutation(v.begin()+1,v.end()-1));
	cout<<res;
}
