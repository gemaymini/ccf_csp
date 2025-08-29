#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int p[N];
int sz[N];
void init(int n){
    for(int i=0;i<n;i++){
        p[i]=i;
        sz[i]=1;
    }
}

int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}

void merge(int a,int b){
    int ra=find(a),rb=find(b);
    if(ra==rb)return;
    else{
        p[ra]=rb;
        sz[rb]+=sz[ra];
    }
}

int query(int x){
    return sz[find(x)];
}

int main(){
    int n,m;cin>>n>>m;
    init(n);
    string c;
    int a,b;
    while(m--){
        cin>>c;
        if(c=="C"){
            cin>>a>>b;
            merge(a,b);
        }else if(c=="Q1"){
            cin>>a>>b;
            if(find(a)==find(b))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }else {
            cin>>a;
            cout<<query(a)<<endl;
        }
    }
}