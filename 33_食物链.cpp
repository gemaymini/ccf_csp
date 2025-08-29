#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
const int K=1e5+10;
int p[3*N+10];
// x 吃x的 被x吃的

void init(int n){
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
}

int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}

void merge(int a,int b){
    int ra=find(a),rb=find(b);
    if(ra==rb)return;
    else p[ra]=rb;
}

int main(){
    int n,k;
    int res=0;
    cin>>n>>k;
    init(3*n);
    for(int i=0;i<k;i++){
        int d,x,y;cin>>d>>x>>y;
        if(x>n||y>n||(d==2 && x==y)){
            res++;
            continue;
        }
        if(d==1){
            if(find(x)==find(n+y)||find(y)==find(n+x)){
                res++;
                continue;
            }
            merge(x,y);
            merge(n+x,n+y);
            merge(2*n+x,2*n+y);
        }else{
            if(find(x)==find(y)||find(y)==find(n+x)){
                res++;
                continue;
            }
            merge(x,n+y);
            merge(2*n+y,n+x);
            merge(2*n+x,y);

        }
    }
    cout<<res;
}