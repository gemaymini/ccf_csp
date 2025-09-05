#include<bits/stdc++.h>

using namespace std;
int func(string a,string b){
    int dp[15][15];
    for(int i=0;i<a.size();i++)dp[i][0]=i;
    for(int j=0;j<b.size();j++)dp[0][j]=j;
    
    for(int i=1;i<a.size();i++){
        for(int j=1;j<b.size();j++){
            int c1,c2,c3;
            if(a[i]==b[j]){
                c1=dp[i-1][j-1];
            }else{
                c1=dp[i-1][j-1]+1;
            }
            c2=dp[i-1][j]+1;
            c3=dp[i][j-1]+1;
            dp[i][j]=min(c1,min(c2,c3));

        }
    }
    return dp[a.size()-1][b.size()-1];

}  

int main(){
    int n,m;
    cin>>n>>m;

    string s[1005];
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]=" "+s[i];
    }
    for(int i=1;i<=m;i++){
        string ts;
        int cnt;
        cin>>ts>>cnt;
        ts=" "+ts;
        int res=0;
        for(int j=1;j<=n;j++){
            int len=func(ts,s[j]);
            if(len<=cnt){
                res++;
            }
        }
        cout<<res<<endl;
    }
}