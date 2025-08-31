#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>node;
const int N=1e5+10;
int sz[N];
int dep[N];
int n;
int num=INT_MAX;
void dfs1(int p,int x)
{
    sz[x]=1;
    for(auto& ne:node[x]){
        if(ne!=p){
        dep[ne]=dep[x]+1;
        dfs1(x,ne);
        sz[x]+=sz[ne];
        }

    }

}
bool check(int p,int x){
    for(auto &ne:node[x]){
        if(ne!=p&&sz[ne]>n/2){
            return false;
        }
    }
    if(n-sz[x]<n/2)return true;
    else return false;

}
void dfs2(int p,int x){
    // cout<<p<<" "<<x<<endl;
    if(check(p,x)){
        int res=0;
        for(auto& ne :node[x]){
            if(ne!=p)
                res=max(res,sz[ne]);
        }
        res=max(res,n-sz[x]);
        num=min(res,num);
        return;
    }
    for(auto& ne :node[x]){
        if(ne!=p){
            dfs2(x,ne); 
        }
    }
}
int main(){
    cin>>n;
    node.resize(n+1);
    for(int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        // cout<<"<<"<<endl;
        node[x].push_back(y);
        node[y].push_back(x);
    }

    dfs1(0,1);
    dfs2(0,1);
    cout<<num;
}