#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int q[N],tt;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        while(tt>0&&q[tt-1]>=x){
            tt--;
        }
        if(tt>0)cout<<q[tt-1]<<" ";
        else cout<<-1<<" ";
        q[tt++]=x;
    }    
}