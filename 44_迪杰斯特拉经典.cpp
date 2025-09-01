#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m;
int g[N][N],d[N];
bool vis[N];
void dijkstra(){
    d[1]=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&(t==-1||d[t]>d[j])){
                t=j;
            }
        }
        vis[t]=true;
        for(int j=1;j<=n;j++){
            d[j]=min(d[j],d[t]+g[t][j]);
        }
    }
}

int main(){
    cin>>n>>m;
    int a,b,c;
    memset(g,0x3f,sizeof g);
    memset(d,0x3f,sizeof d);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);    
    }
    dijkstra();
    if(d[n]==0x3f3f3f3f)cout<<"-1";
    else cout<<d[n];

}
// 用于单源最短路径,正权值边的问题.遍历n轮,每次找出离源点最近的未访问点,利用这个点去松弛其他点.