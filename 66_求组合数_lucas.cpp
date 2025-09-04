#include<bits/stdc++.h>
using namespace std;
#define int long long

int qmi(int a,int k,int p)
{
    int res=1;
    while(k){
        if(k&1)res=(res*a)%p;
        k>>=1;
        a=(a*a)%p;
    }
    return res;
}

int C(int a,int b,int p){
    int res=1;
    for(int i=1,j=a;i<=b;i++,j--){
        res=(res*j)%p;
        res=(res*qmi(i,p-2,p))%p;
    }
    return res;
}

int lucas(int a,int b,int p){
    if(a<p&&b<p){
        return C(a,b,p);
    }
    return C(a%p,b%p,p)*lucas(a/p,b/p,p)%p;
}
signed main(){
    int n;
    cin>>n;
    while(n--){
        int a,b,p;
        cin>>a>>b>>p;
        cout<<lucas(a,b,p)<<endl;
    }
}