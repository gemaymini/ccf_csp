#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e4+5;
struct cow{
    int w,s;
    bool operator<(const cow& c)const {
        if( w+s==c.w+c.s){
            return s<c.s;
        }else{
            return w+s<c.w+c.s ;
        }

    }
};
cow c[N];
signed main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
      int w,s;cin>>w>>s;
      c[i]={w,s};  
    }
    sort(c,c+n);
    int sum=0;
    int res=INT_MIN;
    for(int i=0;i<n;i++){
        res=max(res,sum-c[i].s);
        sum+=c[i].w;
    }
    cout<<res;
}