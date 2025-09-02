#include<bits/stdc++.h>
using namespace std;
#define int long long

int quick_mi(int a,int k ,int p ){
    int res=1;
    while(k){
        if(k&1)res=res*a%p;
        k>>=1;
        a=a*a%p;
    }
    return res;
}

signed main(){
    int n;
    cin>>n;
    while(n--){
        int a,b,p;
        cin>>a>>b>>p;
        cout<<quick_mi(a,b,p)<<endl;
    }
}