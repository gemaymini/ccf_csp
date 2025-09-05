#include<bits/stdc++.h>
using namespace std;
const int M=1e4+5,N=110;
int n,k;
int f[M],s[N];
int sg(int x){
    if(f[x]!=-1){
        return f[x];
    }
    
    set<int>S;
    for(int i=0;i<k;i++){
        if(x>=s[i]){
            S.insert(sg(x-s[i]));
        }
    }

    for(int i=0;;i++){
        if(!S.count(i)){
            return f[x]=i;
        }
    }

}
int main(){

    memset(f,-1,sizeof f);
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>s[i];
    }
    int n;
    int res=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        res^=sg(x);
    }
    if(res==0){
        cout<<"No"<<endl;
    }else cout<<"Yes"<<endl;
}