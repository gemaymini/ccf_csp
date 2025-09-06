#include<bits/stdc++.h>
using namespace std;
struct edge{
    int l, r;
    bool operator<(const edge&  e)const{
        return r<e.r;
    }
};
const int N=100010;
edge e[N];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        e[i]={a,b};
    }

    sort(e,e+n);
    int cnt=0;
    int t=-1e9-7;
    for(int i=0;i<n;i++){
        if(t<e[i].l){
            t=e[i].r;
            cnt++;
        }
    }
    cout<<cnt;
}