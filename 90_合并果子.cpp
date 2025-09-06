#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
priority_queue<int,vector<int>,greater<int>>q;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        q.push(a);
    }
    int res=0;
    while(q.size()>1){
        int x=q.top();
        q.pop();
        int y=q.top();
        q.pop();
        res+=x+y;
        q.push(x+y);
    }
    cout<<res;
}