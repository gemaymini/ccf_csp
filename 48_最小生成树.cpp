#include<bits/stdc++.h>
using namespace std;
const int N=510,M=1e5+5;
int g[N][N];
int n,m,dis[N];
bool vis[N];
int res;
void prim(){
    int s=1;
    vis[1]=true;
    for(int i=1;i<n;i++){
        int t=-1;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&(t==-1||dis[t]>dis[i])){
                t=i;
            }
        }
        res+=g[t][s];
        vis[t]=true;
        for(int i=1;i<=n;i++){
            dis[i]=min(dis[i],g[i][t]);
        }
        s=t;
    }
}
int main(){
    cin>>n>>m;
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;
    for(int i=1;i<=m;i++){
        int x,y,d;
        cin>>x>>y>>d;
        g[x][y]=d;
        g[y][x]=d;
    }
    prim();
    cout<<res;


}