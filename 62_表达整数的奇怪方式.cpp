#include<bits/stdc++.h>
using namespace std;
#define int long long
int exgcd(int a,int b,int& x,int& y)
{
    if(!b){
        x=1;y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;

}
signed main(){
    int n;cin>>n;
    int a1,m1;
    cin>>a1>>m1;
    bool flag=false;
    for(int i=1;i<n;i++){
        int a2,m2,k1,k2;
        cin>>a2>>m2;
        int d=exgcd(a1,a2,k1,k2);
        
        if((m2-m1)%d){
            flag=true;
            break;
        }
        k1=k1*(m2-m1)/d;
        int t=a2/d;
        k1=(k1%t+t)%t;
        m1=k1*a1+m1;
        a1=abs(a1/d*a2);
    }
    if(flag){
        cout<<"-1"<<endl;
    }else {
        cout<<(m1%a1+a1)%a1;
    }

}