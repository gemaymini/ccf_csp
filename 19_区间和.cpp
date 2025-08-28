#include<bits/stdc++.h>
using namespace std;

const int N=3e5+10;
int a[N],b[N];
vector<pair<int,int>>add,query;
vector<int>all;
int find(int x){
    int l=-1,r=all.size();
    while(l+1!=r){
        int mid =(l+r)>>1;
        if(all[mid]<=x)l=mid;
        else r=mid;
    }
    return l;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x,c;cin>>x>>c;
        add.push_back({x,c});
        all.push_back(x);
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        all.push_back(l);
        all.push_back(r);
        query.push_back({l,r});
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(auto &[x,c]:add){
        x=find(x);
        a[x]+=c;
    }
    b[0]=a[0];
    for(int i=1;i<all.size();i++){
        b[i]=b[i-1]+a[i];
    }
    for(auto&[l,r]:query){
        l=find(l);
        r=find(r);
        cout<<b[r]-b[l-1]<<endl;
    }
}