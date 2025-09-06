#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int num[N*2],idx;

int main(){
    int n;
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        num[idx++]=a*2;
        num[idx++]=b*2+1;
    }
    int res=0,t=0;
    sort(num,num+idx);
    for(int i=0;i<idx;i++){
        if(num[i]%2==0){
            t++;
            res=max(res,t);
        }else{
            t--;
        }
    }
    cout<<res;
}