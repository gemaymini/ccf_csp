#include<bits/stdc++.h>
using namespace std;

vector<int> sub(vector<int>&a,vector<int>&b){
    int t=0;
    vector<int>c;
    for(int i=0;i<a.size()||i<b.size();i++){
        if(i<a.size())t+=a[i];
        if(i<b.size())t-=b[i];
        if(t<0){
            c.push_back(t+10);
            t=-1;
        }else{
            c.push_back(t);
            t=0;
        }
    }
    while(c[c.size()-1]==0)c.pop_back();
    return c;
}
int bigger(vector<int>&a,vector<int>&b){
    for(int i =a.size()-1;i>=0;i--){
        if(a[i]>b[i])return 1;
        else if(a[i]<b[i])return 0;
    }
    return 2;
}
int main(){
    string a,b;
    vector<int>A,B;
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--){
        A.push_back(a[i]-'0');
    }
    for(int i=b.size()-1;i>=0;i--){
        B.push_back(b[i]-'0');
    }
    if(a.size()>b.size()){
        auto C=sub(A,B);
        for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    }else if(a.size()<b.size()){
        auto C=sub(B,A);
        cout<<"-";
        for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    }else if(bigger(A,B)==1){
        auto C=sub(A,B);
        for(int i=C.size()-1;i>=0;i--)cout<<C[i];

    }else if(bigger(A,B)==2){
        cout<<0;
    }
    else{
        auto C=sub(B,A);
        cout<<"-";
        for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    }










}