#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
bool is_prime[N];
vector<int>prime;
int main(){
    int n;cin>>n;
    for(int i=2;i<=n;i++){
        if(!is_prime[i]){
            prime.push_back(i);
            
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=n;j++){
                is_prime[i*prime[j]]=true;
                if(i%prime[j]==0)break;
            }
    }
    cout<<prime.size();
}