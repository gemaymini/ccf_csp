#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int q[N],f[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>q[i];
    for(int i=1;i<=n;i++)f[i]=f[i-1]+q[i];
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<f[r]-f[l-1]<<endl;
    }

}