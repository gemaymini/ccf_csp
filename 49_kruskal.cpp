#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+5,M=2e5+10;
int p[N];
void init(){
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
}

int find(int x){
    return x==p[x]?x:p[x]=find(p[x]);
}

void merge(int a,int b){
    int ra=find(a),rb=find(b);
    if(ra==rb){
        return;
    }else {
        p[ra]=rb;
    }
}
struct edge{
    int x,y,d;
    bool operator<(const edge& e)const {
        return d>e.d;
    }
};
priority_queue<edge>q;
void kruskal(){
    int t=0;
    int res=0;
    while(t<n-1&&q.size()){
        auto [x,y,d]=q.top();
        q.pop();

        if(find(x)==find(y)){
            continue;
        }
        else{
            res+=d;
            merge(x,y);
            t++;
        }

    }
    if(t<n-1)cout<<"impossible";
    else cout<<res;
}

int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int x,y,d;
        cin>>x>>y>>d;
        if(x==y)continue;
        q.push({x,y,d});
    }
    kruskal();
    return 0;
}