#include<bits/stdc++.h>
using namespace std;

int main(){
    int res=0;
    int n;cin>>n;
    while(n--){
        int x;cin>>x;
        res^=x;
    }
    if(res){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
