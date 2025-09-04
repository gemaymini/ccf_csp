#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
int c[2005][2005];

void init(){
    for(int i=0;i<=2000;i++){
        for(int j=0;j<=i;j++){
            if(j)c[i][j]=(c[i-1][j]+c[i-1][j-1])%N;
            else c[i][j]=1;
        }
    }
}
int main(){
    int n;cin>>n;
    init();
    while(n--){
        int x,y;
        cin>>x>>y;
        cout<<c[x][y]<<endl;
    }
}