#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct edge{
    int l,r;
    bool operator<(const edge& e)const{
        if(l==e.l){
            return r>e.r;
        }else {
            return l<e.l;
        }
    }
}q[N];
bool vis[N];
int main(){
    int s,t;
    cin>>s>>t;

    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        q[i]={a,b};
    }
    sort(q,q+n);

    for(int i=0;i<n;i++){
        if(q[i].l<=q[i+1].l&&q[i].r>=q[i+1].r){
            q[i+1].l=q[i].l;
            q[i+1].r=q[i].r;

        }
    }

    int res=0;
        // cout<<"begin"<<endl;
        // for(int i=0;i<n;i++){
        //             cout<<q[i].l<< " "<<q[i].r<<endl;
        // }
        // cout<<"end"<<endl;
    for(int i=0;i<n;i++){
        if(q[i].l>s){
            cout<<-1;
            return 0;
        }
        if(q[i+1].l<=s&&q[i+1].r>=q[i].r&&i<n-1){
            continue;
        }
        res++;
        s=q[i].r;
        // cout<<q[i].l<< " "<<q[i].r<<endl;
        if(s>=t){
            break;
        }
    }
    if(s<t){
        cout<<-1;
        return 0;
    }
    cout<<res;
}