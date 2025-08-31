#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<vector<int>>q;
int n,m;
int cnt[N];
queue<int>p;
vector<int>res;
void topu(){
    for(int i=1;i<=n;i++){
        if(cnt[i]==0){
            p.push(i);
            res.push_back(i);
        }
    }
    while(p.size()){
        int x=p.front();
        p.pop();
        for(auto ne:q[x]){
            cnt[ne]--;
            if(cnt[ne]==0){
                p.push(ne);
                res.push_back(ne);
            }
        }
    }

}
int main(){
    cin>>n>>m;
    q.resize(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        q[x].push_back(y);
        cnt[y]++;
    }
    topu();
    if(res.size()<n){
        cout<<-1;
    }else{
        for(auto x:res){
            cout<<x<<" ";
        }
    }

}