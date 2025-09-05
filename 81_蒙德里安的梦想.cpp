#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
bool f[1<<11];
int dp[12][1<<11];

void func(){
    for(int i=1;i<=m;i++){
        for(int lst=0;lst<(1<<n);lst++){
            for(int st=0;st<(1<<n);st++){
                if((lst&st)!=0||!f[lst|st]){
                    continue;
                }
                else{
                    dp[i][st]+=dp[i-1][lst];
                }
            }
        }
    }
    cout<<dp[m][0]<<endl;
}


void init(){    
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    for(int i=0;i<1<<n;i++){
        f[i]=true;
        int cnt=0;
        for(int j=0;j<n;j++){
            if(((i>>j)&1)==0){
                cnt++;
            }else{
                if(cnt&1){
                    f[i]=false;
                    break;
                }else{
                    cnt=0;
                }
            }
        }
        if(cnt&1){
            f[i]=false;
        }
    }
}
signed main(){

    while(cin>>n>>m,n||m){
        init();
        func();
    }
}