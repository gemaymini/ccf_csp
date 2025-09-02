#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<2){
            cout<<"No"<<endl;
            continue;
        }
        bool flag=false;
        for(int i=2;i<=x/i;i++){
            if(x%i==0){
                flag=true;
                break;
            }
        }
        if(!flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        
    }
}