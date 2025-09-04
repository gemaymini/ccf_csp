#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=20;
int p[M];
int num;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>p[i];
    }
    for(int i=1;i<1<<m;i++){
        int t=1,res=0;
        for(int j=0;j<m;j++){
            if(i>>j&1){
                if(t*p[j]>n){
                    t=-1;
                    break;
                }
                t*=p[j];
                res++;
            }
        }
        if(t!=-1){
            if(res%2==0){
                num-=n/t;
            }else {
                num+=n/t;
            }
        }

    }
    cout<<num;
}