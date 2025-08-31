#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int h[N],e[N],ne[N],idx,d[N];
queue<int>q;
void bfs(){
    d[1]=0;
    q.push(1);
    while(q.size()){
        int x=q.front();
        q.pop();
        for(int i=h[x];i!=-1;i=ne[i]){
            if(d[e[i]]==0){
                q.push(e[i]);
                d[e[i]]=d[x]+1;
            }
        }

    }
}
int main(){
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<0;
        return;
    }
    for(int i=1;i<=n;i++){
        h[i]=-1;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        e[idx]=b;
        ne[idx]=h[a];
        h[a]=idx++;
    }
    bfs();
    if(d[n]==0){
        cout<<-1<<endl;
    }else {
        cout<<d[n];
    }
}