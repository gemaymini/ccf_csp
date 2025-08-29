#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int q[N],hh,tt;
void init(){
    hh=0;
    tt=0;
}


void push(int x ){
    q[tt++]=x;
}

void pop(){
    hh++;
}


void empty(){
    if(hh==tt){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
}

void query(){
    cout<<q[hh]<<endl;
}

int main(){
    int m;cin>>m;
    while(m--){
        string s;int x;
        cin>>s;
        if(s=="push")
        {
            cin>>x;
            push(x);
        }else if(s=="pop")
            pop();
        else if(s=="empty")
            empty();
        else query();
    }
    
}