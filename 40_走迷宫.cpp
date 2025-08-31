// #include<bits/stdc++.h>
// using namespace std;
// const int N=110;

// int n,m;
// int h[N][N];
// bool vis[N][N];
// int res=INT_MAX;
// vector<pair<int,int>>mv;

// void bfs(int x,int y,int s){
//     // cout<<x<<" "<<y<<endl;
//     if(h[x][y]==1||s>=res){
//         return;
//     }

//     if(x==n-1&&y==n-1){
//        res=min(res,s); 
//     //    cout<<1;
//     }
//     for(int i=0;i<4;i++){
//         int tx=x+mv[i].first;
//         int ty=y+mv[i].second;
//         // cout<<"-"<<tx<<" "<<ty<<endl;
//         if(tx>=0 && ty>=0 && tx<n && ty<n &&(!vis[tx][ty]))
//         {
//             vis[tx][ty]=true;
//             bfs(tx,ty,s+1);
//             vis[tx][ty]=false;
//         }
//     }
// }
// int main(){
//     cin>>n>>m;
//     //x hang y lie shang xia zuo you
//     mv.push_back({-1,0});
//     mv.push_back({1,0});
//     mv.push_back({0,-1});
//     mv.push_back({0,1});

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>h[i][j];
//         }
//     }
//     bfs(0,0,0);
//     cout<<res;

// }

#include<bits/stdc++.h>
using namespace std;
int n,m;

const int N = 110;
int h[N][N],g[N][N];
queue<pair<int,int>> q;
vector<pair<int,int>>mv;
void bfs(){
    q.push({0,0});
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int tx=x+mv[i].first,ty=y+mv[i].second;
            if(tx>=0&&tx<n&&ty>=0&&ty<m&&g[tx][ty]==-1&&h[tx][ty]==0){
                g[tx][ty]=g[x][y]+1;
                
                q.push({tx,ty});
            }
        }
    }

}

int  main(){
    cin>>n>>m;
    memset(g,-1,sizeof(g));
    mv.push_back({-1,0});
    mv.push_back({1,0});
    mv.push_back({0,-1});
    mv.push_back({0,1});
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>h[i][j];
    g[0][0]=0;
    bfs();
    cout<<g[n-1][m-1];

}
