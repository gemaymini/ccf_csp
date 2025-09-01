#include<bits/stdc++.h>

using namespace std;

int n,m;
const int N=1e5+10,M=2e5+10;
int idx,h[N],e[M],ne[M];
int color[N];

void add(int x,int y){
    e[idx]=y;
    ne[idx]=h[x];
    h[x]=idx++;
}

bool dfs(int u,int c){
    color[u]=c;
    for(int i=h[u];i!=-1;i=ne[i]){
        if(!color[e[i]]){
            if(!dfs(e[i],3-c)){
                return false;
            }
        }else if(color[e[i]]==color[u]){
            return false;
        }
    }
    return true;
}

int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(!color[i]){
            if(!dfs(i,1)){
                flag=false;
                break;
            }   
        }
    }
    if(!flag)cout<<"No";
    else cout<<"Yes";

}