#include<bits/stdc++.h>
using namespace std;
bool func(int x){
    return x-(x&-x)>0;
}

int main(){
    int n;cin>>n;
    while(n--){
        int num=1;
        int x;cin>>x;
        if(x==0){
            cout<<0<<" ";
            continue;
        }
        while(func(x)){
            num++;
            x-=(x&-x);
        }
        cout<<num<<" ";
    }
}