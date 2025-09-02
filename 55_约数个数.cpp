#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e9+5,P=1e9+7;
map<int,int>m;
void func(int x){
    for(int i=2;i<=x/i;i++){
        if(x%i==0){
            int s=0;
            while(x%i==0){
                x=x/i;
                s++;
            }
            m[i]+=s;
        }
    }
    if(x>1)m[x]++;
}
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        func(x);
    }
    int res=1;
    for(auto e:m){
        res*=(1+e.second);
        res=(res+P)%P;
    }
    cout<<res;
}