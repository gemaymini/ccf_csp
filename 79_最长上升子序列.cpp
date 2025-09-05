#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> dp;
int search(int x){
    int i=-1,j=dp.size();
    while(i+1!=j){
        int mid=(i+j)>>1;
        if(dp[mid]<x)i=mid;
        else j=mid;
    }
    return i;
}
int main(){
    dp.push_back(-1e9-5);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        int idx=search(a)+1;
        if(idx==dp.size())dp.push_back(a);
        else dp[idx]=a;
    }
    cout<<dp.size()-1;

}