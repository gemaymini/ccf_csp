#include<bits/stdc++.h>
using namespace std;
const int N=510,M=1e5+5;
int g[N][N];
int n,m,dis[N];
bool vis[N];
int res;
void prim(){
    vis[1]=true;
    for(int j=1;j<=n;j++){
        dis[j]=min(dis[j],g[j][1]);
     }
    for(int i=1;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&(t==-1||dis[t]>dis[j])){
                if(dis[j]==0x3f3f3f3f) continue;
                t=j;
            }
        }
        if(t==-1){
            cout<<"impossible";
            exit(0);
        }
        res+=dis[t];
        vis[t]=true;
        for(int j=1;j<=n;j++){
            dis[j]=min(dis[j],g[j][t]);
        }
    }
}
int main(){
    cin>>n>>m;
    memset(dis,0x3f,sizeof dis);
    memset(g,0x3f,sizeof g);
    dis[1]=0;
    for(int i=1;i<=m;i++){
        int x,y,d;
        cin>>x>>y>>d;
        if(x==y)continue;
        g[x][y]=min(d,g[x][y]);
        g[y][x]=min(d,g[y][x]);
    }
    prim();

    cout<<res;

}