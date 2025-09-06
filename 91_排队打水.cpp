#include<bits/stdc++.h>
using namespace std;
#define int long long 

priority_queue<int,vector<int>,greater<int>>q;
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        q.push(a);
    }
    int res=0;
    int sum=0;
    while(q.size()){
        int x=q.top();
        q.pop();
        res+=sum;

        sum+=x;
    }
    cout<<res;
}