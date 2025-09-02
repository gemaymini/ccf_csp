#include<bits/stdc++.h>
using namespace std;
int lcd(int x,int y){
    if(y==0){
        return x;
    }else{
        return lcd(y,x%y);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if(x>y)
            cout<<lcd(x,y)<<endl;
        else cout<<lcd(y,x)<<endl;
    }
}