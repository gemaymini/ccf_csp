#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;

int s[N],tt;
void push(int x){
    s[++tt]=x;
}
void pop(){
    if(tt>0)
        tt--;
}
void empty(){
    if(tt==0){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
}
void query(){
    cout<<s[tt]<<endl;
}
int main(){
    int m;
    cin>>m;
    while(m--){
        string s;
        cin>>s;
        if(s=="push"){
            int x;
            cin>>x;
            push(x);
        }else if(s=="pop")
            pop();
        else if(s=="empty")
            empty();
        else query();
    }
}