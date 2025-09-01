#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int INF=0x3f3f3f3f;
int n,m,k;

struct {
    int x,y,z;
}edge[N];

int d[510];

int main(){
    cin>>n>>m>>k;
    
    // 初始化距离数组
    memset(d,0x3f,sizeof d);
    d[1]=0;
    
    // 读取边信息
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edge[i]={x,y,z};
    }
    
    // 进行k次松弛操作
    for(int i=1;i<=k;i++){
        int last[510];
        memcpy(last,d,sizeof d);  // 备份上一轮的距离
        
        for(int j=1;j<=m;j++){
            auto [x,y,z]=edge[j];
            // 检查起点是否可达，避免溢出
            if(last[x]!=INF && last[x]+z<d[y]){
                d[y]=last[x]+z;
            }
        }
    }
    
    if(d[n]==INF) cout<<"impossible";
    else cout<<d[n];
    
    return 0;
}