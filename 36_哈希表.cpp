#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;

int h[N],nu=0x3f3f3f3f;

int find(int x){
    int k=(x%N+N)%N;
    while(h[k]!=nu&&h[k]!=x){
        k++;
        if(k==N)k=0;
    }
    return k;
}

int main(){
    int n;cin>>n;
    memset(h,0x3f,sizeof(h));
    while(n--){
        char c;int x;
        cin>>c>>x;
        if(c=='I'){
            h[find(x)]=x;
        }else{
            if(h[find(x)]!=nu)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}