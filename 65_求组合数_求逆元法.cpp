#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
const int P=1e9+7;
int fac[N],ifac[N];
int qmi(int x,int k,int p){
    int res=1;
    while(k){
        if(k&1)res=(res*x)%p;
        k>>=1;
        x=(x*x)%p;
    }
    return res;
}
void init(){
    fac[0]=1;ifac[0]=1;
    for(int i=1;i<=N;i++){
        fac[i]=fac[i-1]*i%P;
        ifac[i]=ifac[i-1]*qmi(i,P-2,P)%P;
    }
}
signed main(){
    int n;cin>>n;
    init();
    while(n--){
        int a,b;
        cin>>a>>b;
        cout<<fac[a]*ifac[a-b]%P*ifac[b]%P<<endl;
    }
}