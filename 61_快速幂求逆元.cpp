#include<bits/stdc++.h>
using namespace std;
#define int long long 
int qmi(int a,int k,int p){
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
        int a,p;
        cin>>a>>p;
        int res=qmi(a,p-2,p);
        if(a%p)cout<<res<<endl;
        else cout<<"impossible"<<endl;
    }
}