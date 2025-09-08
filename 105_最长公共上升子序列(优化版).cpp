#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
int d[N][N];//d[i][j]是从头到a[i],b[j]，并以b[j]结尾的最长公共子序列。
//以a[i]结尾 看倒数第二个
//不以a[i]结尾 d[i-1][j]

int a[N], b[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	
	for(int i=1;i<=n;i++){
		int maxv=1;
		for(int j=1;j<=n;j++){
			d[i][j]=max(d[i][j],d[i-1][j]);
			if(a[i]==b[j]){
				d[i][j]=max(d[i][j],maxv);				
			}
			if(a[i]>b[j])maxv=max(maxv,d[i-1][j]+1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
//		cout<<d[n][i]<<endl;
		ans=max(ans,d[n][i]);
	}
	cout<<ans;
}
