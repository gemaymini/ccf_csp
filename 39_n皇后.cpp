// #include<bits/stdc++.h>
// using namespace std;

// const int N=10;
// int n;
// char qp[N][N];
// bool col[N],dq[2*N],udq[2*N];

// void dfs(int u){
//     if(u==n){
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++)
//                 printf("%c",qp[i][j]);
//             cout<<endl;
//         }
//         cout<<endl;
//     }
//     for(int i=0;i<n;i++){
//         if(!col[i]&&!dq[u+i]&&!udq[n-i+u]){
//             col[i]=dq[u+i]=udq[n-i+u]=true;
//             qp[u][i]='Q';
//             dfs(u+1);
//             col[i]=dq[u+i]=udq[n-i+u]=false;
//             qp[u][i]='.';
//         }
//     }
// }


// int main(){
//     cin>>n;
//     memset(qp,'.',sizeof(qp));
//     dfs(0);
// }

#include<bits/stdc++.h>
using namespace std;

const int N=10;

int n;

char qp[N][N];
bool col[N],dg[2*N],udg[2*N],row[N];

void dfs(int x,int y,int s){
    if(y==n){
        y=0;x++;
    }
    if(x==n){
        if(s==n){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    cout<<qp[i][j];
                cout<<endl;
            }
            cout<<endl;
        }
        return;
    }

    dfs(x,y+1,s);
    if(!col[y]&&!row[x]&&!dg[x+y]&&!udg[x-y+n]){
        qp[x][y]='Q';
        col[y]=row[x]=dg[x+y]=udg[x-y+n]=true;
        dfs(x,y+1,s+1);
        qp[x][y]='.';
        col[y]=row[x]=dg[x+y]=udg[x-y+n]=false;
    }

}

int main(){
    
    cin>>n;
    memset(qp,'.',sizeof(qp));
    dfs(0,0,0);
}