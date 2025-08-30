 #include<bits/stdc++.h>
 using namespace std;
 const int N = 1e5;

 int h[N],sz;
 void down(int u){
    int t=u;
    if(u*2<=sz&&h[u*2]<h[t])t=u*2;
    if(u*2+1<=sz&&h[u*2+1]<h[t])t=u*2+1;
    if(u!=t){
        swap(h[u],h[t]);
        down(t);
    }

 }

 int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>h[i];
    sz=n;
    for(int i=n/2;i;i--)down(i);
    while(m--){
        cout<<h[1]<<endl;
        h[1]=h[sz];
        sz--;
        down(1);
    }
    return 0;
 }