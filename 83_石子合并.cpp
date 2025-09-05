#include<bits/stdc++.h>
using namespace std;
const int N=305;
int a[N][N];
int q[N],sum[N];
int main(){
    int n;cin>>n;
    memset(a,0x3f,sizeof a);

    for(int i=1;i<=n;i++){
        cin>>q[i];
        sum[i]=sum[i-1]+q[i];
        a[i][i]=0;
    }

    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            for(int k=i;k<j;k++){
                a[i][j]=min(a[i][k]+a[k+1][j]+sum[j]-sum[i-1],a[i][j]);
            }
        }
    }
    cout<<a[1][n];
}