#include<bits/stdc++.h>
using namespace std;
const int N=15e4+10;
int n,m;
struct node{
    int n;
    int d;
    bool operator< (const node& b)const{
        return d>b.d;
    }
};
int dis[N];
priority_queue<node>q;
vector<vector<node>>v;
bool vis[N];
void dijkstra(){
    dis[1]=0;
    q.push({1,0});
    while(q.size()){
        auto [x,dx]=q.top();
        q.pop();
        if(vis[x]){
            continue;
            
        }

        vis[x]=true;
        for(auto [y,dy]:v[x]){
            if(dy+dis[x]<dis[y]){
                dis[y]=dis[x]+dy;
                q.push({y,dis[y]});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    memset(dis,0x3f,sizeof dis);
    v.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    dijkstra();


    if(dis[n]==0x3f3f3f3f)cout<<"-1";
    else cout<<dis[n];
}