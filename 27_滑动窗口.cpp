#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int e[N],hh,tt,ma[N],mi[N];
vector<pair<int,int>>q(N);
void push(int x,int k){
    q[tt++]={x,k};
}
void pop(){
    hh++;
}
bool full(int k){
    return tt-hh>k;
}
bool empty(){
    return tt==hh;
}
int main(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>e[i];
    }
    for(int i=1;i<=n;i++){
        while(!empty()&&q[tt-1].first<e[i]){
            tt--;
        }
        push(e[i],i);
        while(full(k)||i-q[hh].second>=k)pop();

        ma[i]=q[hh].first;
    }
    hh=0;tt=0;

    for(int i=1;i<=n;i++){
        while(!empty()&&q[tt-1].first>e[i]){
            tt--;
        }
        push(e[i],i);
        while(full(k)||i-q[hh].second>=k)pop();

        mi[i]=q[hh].first;
    }

    for(int i=k;i<=n;i++){
        cout<<mi[i]<<" ";
    }cout<<endl;
    for(int i=k;i<=n;i++)
    {
        cout<<ma[i]<<" ";
    }
}