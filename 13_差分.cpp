#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int q[N],f[N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>q[i];
    for(int i=1;i<=n;i++)f[i]=q[i]-q[i-1];
    while(m--){
        int l,r,c;
        cin>>l>>r>>c;
        f[l]+=c;
        f[r+1]-=c;
    }
    for(int i=1;i<=n;i++){
        q[i]=q[i-1]+f[i];
    }
    for(int i=1;i<=n;i++)cout<<q[i]<<" ";
}