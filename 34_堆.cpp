 #include<bits/stdc++.h>
 using namespace std;
 const int N = 1e5;

<<<<<<< HEAD
 int h[N],sz;
 void down(int u){
    int t=u;
    if(u*2<=sz&&h[u*2]<h[t])t=u*2;
    if(u*2+1<=sz&&h[u*2+1]<h[t])t=u*2+1;
=======
 int h[N],size;
 void down(int u){
    int t=u;
    if(u*2<=size&&h[u*2]<h[t])t=u*2;
    if(u*2+1<=size&&h[u*2+1]<h[t])t=u*2+1;
>>>>>>> 6aaaf74 (submit)
    if(u!=t){
        swap(h[u],h[t]);
        down(t);
    }

 }

 int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>h[i];
<<<<<<< HEAD
    sz=n;
    for(int i=n/2;i;i--)down(i);
    while(m--){
        cout<<h[1]<<endl;
        h[1]=h[sz];
        sz--;
=======
    size=n;
    for(int i=n/2;i;i--)down(i);
    while(m--){
        cout<<h[1]<<endl;
        h[1]=h[size];
        size--;
>>>>>>> 6aaaf74 (submit)
        down(1);
    }
    return 0;
 }