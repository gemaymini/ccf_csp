#include<bits/stdc++.h>
using namespace std;

const int N=10;
int path[N];
bool v[N];
int n;

void dfs(int u){
    if(u==n+1){
        for(int i = 1;i<=n;i++)cout<<path[i]<<" ";
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        if(!v[i]){
            path[u]=i;
            v[i]=1;
            dfs(u+1);
            v[i]=0;
        }
    }
}

int main(){
    cin>>n;
    dfs(1);
}