#include<bits/stdc++.h>
#include<cmath>
using namespace std;
const int N=105;
const double eps=1e-6;
double g[N][N+1];
int n;
int guss(){
    int r,c;
    for(r=0,c=0;c<n;c++){
        int t=r;
        for(int i=r;i<n;i++){
            if(fabs(g[i][c])>fabs(g[t][c])){
                t=i;
            }
        }
        if(fabs(g[t][c])<eps)continue;
        for(int i=c;i<=n;i++){
            swap(g[r][i],g[t][i]);
        }
        for(int i=n;i>=c;i--){
            g[r][i]/=g[r][c];
        }
        for(int i=r+1;i<n;i++){

                for(int j=c+1;j<=n;j++){
                    g[i][j]-=g[i][c]*g[r][j];
                }
            g[i][c]=0;
        }
        r++;
    }
    if(r<n){
        for(int i=r;i<n;i++){
            if(fabs(g[i][n])>eps)return 0;
        }
        return 1;
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--){
            g[j][n]-=g[i][n]*g[j][i];
            g[j][i]=0;
        }
        
    }
    return 2;
}


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            cin>>g[i][j];
        }
    }    

    int res=guss();
    if(res==2){
        for(int i=0;i<n;i++){
            printf("%.2f\n",g[i][n]);
        }  
    }else if(res==1){
        cout<<"Infinite group solutions"<<endl;
    }else{
        cout<<"No solution"<<endl;
    }
   
}