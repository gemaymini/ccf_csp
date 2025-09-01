#include<bits/stdc++.h>
using namespace std;
const int N=510,M=1e5+10;
int idx,h[N],e[M],ne[M];
int n1,n2,m;
bool st[N];
int match[N];
void add(int x,int y){
    e[idx]=y;
    ne[idx]=h[x];
    h[x]=idx++;
}

bool find(int x){
    for(int i=h[x];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j]){
            st[j]=true;
            if(!match[j]||find(match[j])){
                match[j]=x;
                return true;
            }
        }
    }
    return false;
}


int main(){
    cin>>n1>>n2>>m;
    memset(h,-1,sizeof h);
    int res=0;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        add(x,y);

    }
    for(int i =1;i<=n1;i++)
    {
        memset(st,false,sizeof st);
        if(find(i))res++;
    }
    cout<<res;
}