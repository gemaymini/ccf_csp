#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int n,m;
int dis[N],e[N],ne[N],h[N],idx,v[N];
bool vis[N];
void add(int x,int y,int d){
    e[idx]=d;
    v[idx]=y;
    ne[idx]=h[x];
    h[x]=idx++;
}
queue<int>q;

void spfa(){
    q.push(1);
    vis[1]=true;
    while(q.size()){
        int t=q.front();
        vis[t]=false;
        q.pop();
        for(int i=h[t];i!=-1;i=ne[i]){
            if(dis[t]+e[i]<dis[v[i]]){
                dis[v[i]]=dis[t]+e[i];
                if(!vis[v[i]]){
                    q.push(v[i]);
                    vis[v[i]]=true;
                }
            }

        }
    }
}
int main(){
    cin>>n>>m;
    memset(dis,0x3f,sizeof dis);
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int x,y,d;
        cin>>x>>y>>d;
        add(x,y,d);
    }

    dis[1]=0;
    spfa();
    if(dis[n]!=0x3f3f3f3f)cout<<dis[n];
    else cout<<"impossible";
}