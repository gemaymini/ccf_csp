#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
typedef  pair<int,int> PII;

vector<PII> seg;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        seg.push_back({l,r});
    }
    sort(seg.begin(),seg.end());
    int ll=seg[0].first,rr=seg[0].second;
    int res=0;
    for(auto & [l,r]:seg){
        if(rr>=r)continue;
        else if(l<=rr) rr=r;
        else{
            res++;
            ll=l;
            rr=r;
        }
    }
    cout<<res+1;
}