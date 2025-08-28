#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int q[N][N],f[N][N];
int main(){
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>q[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=q[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
        }
    }
    while(p--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<f[x2][y2]-f[x1-1][y2]-f[x2][y1-1]+f[x1-1][y1-1]<<endl;
    }
}