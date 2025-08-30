#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int h[N],ph[N],hp[N],sz;

void heap_swap(int a,int b){
    swap(h[a],h[b]);
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
}

void up(int u){
    while(u/2&&h[u]<h[u/2]){
        heap_swap(u,u/2);
        u>>=1;
    }
}

void down(int u){
    int t=u;
    if(u*2<=sz&&h[u*2]<h[t])t=u*2;
    if(u*2+1<=sz&&h[u*2+1]<h[t])t=u*2+1;
    if(t!=u){
        heap_swap(t,u);
        down(t);
    }
}

int main(){
    int n;cin>>n;
    int m=0;
    while(n--){
        string c;int x,k;
        cin>>c;
        if(c=="I"){
            cin>>x;
            sz++;
            m++;
            h[sz]=x;
            ph[m]=sz;
            hp[sz]=m;
            up(sz);
        }
        else if(c=="PM"){
            cout<<h[1]<<endl;
        }else if(c=="DM"){
            heap_swap(1,sz);
            sz--;
            down(1);
        }else if(c=="D"){
            cin>>k;
            int t=ph[k];
            heap_swap(ph[k],sz);
            sz--;
            up(t);
            down(t);

        }else{
            cin>>k>>x;
            h[ph[k]]=x;
            up(ph[k]),down(ph[k]);
        }
    }
}