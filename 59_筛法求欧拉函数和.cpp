#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+5;
bool is_prime[N];
vector<int>prime;
int phi[N];
signed main(){
    int n;
    cin>>n;
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!is_prime[i]){
            prime.push_back(i);
            phi[i]=i-1;
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=n;j++){
            is_prime[i*prime[j]]=true;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }else{
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        res+=phi[i];
    }
    cout<<res;
}