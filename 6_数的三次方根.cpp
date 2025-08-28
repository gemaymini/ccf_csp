#include<bits/stdc++.h>
using namespace std;

int main(){
    double n;
    cin>>n;
    bool positive = n>0;
    if(n<0)n=-n;
    if(n==0){
        cout<<"0.000000"<<endl;
        return 0;
    }
    double l=0,r=50;
    while(r-l>1e-7){
        double mid=(r+l)/2;
        if(mid*mid*mid>=n){
            r=mid;
        }else{
            l=mid;
        }
    }
    if(positive){
        printf("%.6f",l);
    }else{
        printf("%.6f",-l);
    }

}
