#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int s[N*30][2],idx;

void insert(int x){
    int p=0;
    for(int i=30;i>=0;i--){
        int u=x>>i&1;
        if(!s[p][u])s[p][u]=++idx;
        p=s[p][u];
    }
}

int search(int x){
    int p=0;
    int res=0;
    for(int i=30;i>=0;i--){
        int u=x>>i&1;
        if(s[p][1-u])
        {
            res+=1<<i;
            p=s[p][1-u];
        }else{
            p=s[p][u];
        }
    }
    // cout<<res;
    return res;
}
int q[N];
int main(){
    int n;cin>>n;
    int j=0;
    int m=n;
    while(n--){
        int x;
        cin>>x;
        insert(x);
        q[j++]=x;
    }
    int num=0;
    for(int i=0;i<m;i++){
        // cout<<q[i]<<" ";
        num=max(num,search(q[i]));
    }   
    cout<<num;
}