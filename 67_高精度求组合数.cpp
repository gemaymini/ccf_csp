#include<bits/stdc++.h>
using namespace std;
const int N=5005;
map<int,int>cnt;
bool is_prime[N];
vector<int>prime;
vector<int> mul(vector<int>s,int n){
    vector<int>c;
    int t=0;
    for(int i=0;i<s.size();i++){
        t+=s[i]*n;
        c.push_back(t%10);
        t/=10;
    }
    while(t){
        c.push_back(t%10);
        t/=10;
    }
    return c;
}
void oular(){
    for(int i=2;i<N;i++){
        if(!is_prime[i]){
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=N;j++){
            is_prime[i*prime[j]]=true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
}
void func1(int x,int y){
    for(int i=1,j=x;i<=y;i++,j--){
        int t=j;
        for(int k=0;k<prime.size()&&t/prime[k]>=prime[k];k++){
            if(t%prime[k]==0){
                while(t%prime[k]==0){
                    t/=prime[k];
                    cnt[prime[k]]++;
                }
            }
        }
        if(t>1){
            cnt[t]++;
        }
        t=i;
        for(int k=0;k<prime.size()&&t/prime[k]>=prime[k];k++){
            if(t%prime[k]==0){
                while(t%prime[k]==0){
                    t/=prime[k];
                    cnt[prime[k]]--;
                }
            }
        }
        if(t>1){
            cnt[t]--;
        }
        
    }
    vector<int>s1(1,1);
    for(auto e:cnt){
        int num=e.first,c=e.second;
        if(c>0){
            for(int i=1;i<=c;i++){
                s1=mul(s1,num);
            }
        }
    }
    for(int i=s1.size()-1;i>=0;i--){
        cout<<s1[i];
    }
}


int main(){
    int a,b;
    cin>>a>>b;
    // cout<<"begin"<<endl;
    oular();
    func1(a,b);
    
}