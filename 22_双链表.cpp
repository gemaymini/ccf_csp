#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int idx,l[N],r[N],e[N];

void init(){
    r[0]=1;
    l[1]=0;
    idx=2;
}

void add_head(int x){
    e[idx]=x;
    l[idx]=0;
    r[idx]=r[0];
    l[r[0]]=idx;
    r[0]=idx;
    idx++;
}

void add_end(int x){
    e[idx]=x;
    r[idx]=1;
    l[idx]=l[1];
    r[l[1]]=idx;
    l[1]=idx;
    idx++;
}

void insert_right(int k,int x){
    e[idx]=x;
    l[idx]=k;
    r[idx]=r[k];
    l[r[k]]=idx;
    r[k]=idx;
    idx++;
}

void insert_left(int k,int x){
    insert_right(l[k],x);
}

void remove(int k){
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}

int main(){
    int m;cin>>m;
    init();
    while(m--){
        char c;
        cin>>c;
        int k,x;
        if(c=='L'){
            cin>>x;
            add_head(x);
        }else if(c=='R'){
            cin>>x;
            add_end(x);
        } else if(c=='D'){
            cin>>k;
            remove(k+1);
        }else if(c=='I'){
            char v;cin>>v;
            if(v=='L'){
                cin>>k>>x;
                insert_left(k+1,x);
            }else{
                cin>>k>>x;
                insert_right(k+1,x);
            }
        }
    }
        for(int i=r[0];i!=1;i=r[i])cout<<e[i]<<" ";
}