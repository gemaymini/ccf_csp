#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N=1e5+10,P=131;
ULL h[N],p[N];


int main(){
    int n,m;cin>>n>>m;
    string s;
    cin>>s;
    p[0]=1;
    
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*P;
    }    
    for(int i=1;i<=n;i++){
        h[i]=h[i-1]*P+s[i-1];

    }
    
    while(m--){
        int l1,l2,r1,r2;
        cin>>l1>>r1>>l2>>r2;
        // cout<<h[r1]-h[l1-1]*p[r1-l1+1]<<" "<<h[r2]-h[l2-1]*p[r2-l2+1]<<endl;
        if(h[r1]-h[l1-1]*p[r1-l1+1]==h[r2]-h[l2-1]*p[r2-l2+1]){
            cout<<"Yes"<<endl;
        }else cout<<"No"<<endl;
        
    }
}