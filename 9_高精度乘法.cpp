#include<bits/stdc++.h>
using namespace std;
void mul(vector<int>s,int b){
    int t=0;
    vector<int>c;
    if(b==0){
        cout<<0;
        return;
    }
    for(int i=0;i<s.size();i++){
        t+=s[i]*b;
        c.push_back(t%10);
        t/=10;
    }
    while(t){
        c.push_back(t%10);
        t/=10;
    }
    for(int i=c.size()-1;i>=0;i--){
        cout<<c[i];
    }
}
int main(){
    string a;
    cin>>a;
    vector<int>s;
    for(int i=a.size()-1;i>=0;i--){
        s.push_back(a[i]-'0');
    }
    int b;
    cin>>b;
    mul(s,b);
}