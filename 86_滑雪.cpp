#include<bits/stdc++.h>
using namespace std;
const int N=305;
int m[N][N];
int dp[N][N];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int r,c;

int dfs(int x,int y){
    if(dp[x][y]!=0)return dp[x][y];
    dp[x][y]=1;
    for(int i=0;i<4;i++){
        int tx=x+dx[i],ty=y+dy[i];
        // cout<<x<<" "<<y<< ' '<<l << " ";
        // cout<<tx<<" "<<ty<<endl; 

        if(tx>=1&&tx<=r&&ty>=1&&ty<=c&&m[x][y]>m[tx][ty]){
            // cout<<"进入"<<tx<<" "<<ty<<endl;
           dp[x][y]=max(dp[x][y],dfs(tx,ty)+1);
        }
    }
    return dp[x][y];
}

int main(){
cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>m[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            dfs(i,j);
        }
    }
    int res=0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            res=max(res,dp[i][j]);
        }
    }
    cout<<res;

}