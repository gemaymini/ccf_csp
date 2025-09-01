#include<bits/stdc++.h>
using namespace std;
const int N=2010,M=1e4+5;
int n,m;
int idx,h[N],e[M],v[M],ne[M];
int dis[N],cnt[N];
bool vis[N];
void add(int x,int y,int d){
    e[idx]=d;
    v[idx]=y;
    ne[idx]=h[x];
    h[x]=idx++;
}
queue<int>q;
bool spfa(){
    for(int i=1;i<=n;i++){
        q.push(i);
        vis[i]=true;
    }

    while(q.size()){
        int t=q.front();
        q.pop();
        vis[t]=false;
        for(int i=h[t];i!=-1;i=ne[i]){
            if(dis[t]+e[i]<dis[v[i]]){
                dis[v[i]]=dis[t]+e[i];
                cnt[v[i]]=cnt[t]+1;
                if(cnt[v[i]]>=n){
                    return true;
                }
                if(!vis[v[i]]){
                    vis[v[i]]=true;
                    q.push(v[i]);
                }
            }


        }
    }
    return false;
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int x,y,d;
        scanf("%d%d%d", &x, &y, &d);
        add(x,y,d);
    }

    if(spfa()) cout<<"Yes";
    else cout<<"No";
}