#include<bits/stdc++.h>
using namespace std;
int count(int n,int x){
    int cnt=0;
    for(int i=n;i;i/=10){
        cnt++;
    }
    int res=0;
    for(int i=1;i<=cnt;i++){
        int r=pow(10,i-1);
        int l=n/r/10;
        if(x){
            res+=r*l;
        }else {
            res+=(l-1)*r;
        }

        int d=(n/r)%10;
        if(d>x){
            res+=r;
        }else if(d==x){
            res+=(n%r)+1;
        }
    }
    return res;
}
int main(){
    int a,b;
    while(cin>>a>>b,a||b){
        for(int i=0;i<=9;i++){
            if(a<b)swap(a,b);
            cout<<count(a,i)-count(b-1,i)<<" ";
        }
        cout<<endl;
    }
}