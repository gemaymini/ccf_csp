#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int q[N];
set<int> s;
int main(){
    int n;cin>>n;

    for(int i=1;i<=n;i++)cin>>q[i];
    int ans=1;
    s.insert(q[1]);
    for(int i=2,j=1;i<=n;i++){
        while(j<i&&s.find(q[i])!=s.end()){
            s.erase(q[j]);
            j++;
            ans=max(i-j+1,ans);
        }
        s.insert(q[i]);
        ans=max(ans,i-j+1);
    }
    cout<<ans;
}