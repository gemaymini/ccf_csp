#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;

struct Edge {
    int x,y,d;
};
Edge e[N];
int n,m,k;
int d[510],backup_d[510];

void bellman(){
    for(int i=0;i<k;i++)
    {
        memcpy(backup_d,d,sizeof d);
        for(int j=0;j<m;j++){
            int x = e[j].x, y = e[j].y, dw = e[j].d;
            if( backup_d[x]+dw<d[y])
            {
                d[y]=backup_d[x]+dw;
            }
        }
    }
}

int main(){
    cin>>n>>m>>k;
    memset(d,0x3f,sizeof d);
    d[1]=0;
    for(int i=0;i<m;i++){
        int x,y,d;
        cin>>x>>y>>d;
        e[i]={x,y,d};
    }

    bellman();
    if(d[n]==0x3f3f3f3f)cout<<"impossible";
    else cout<<d[n];
}