#include<bits/stdc++.h>
using namespace std;
const int N=20;
typedef pair<double,double> PDD;
#define x first
#define y second
int f[1<<N];
PDD p[N];
int path[N][N];
int cmp(double x,double y){
	if(fabs(x-y)<1e-8)return 0;
	if(x>y)return 1;
	else return -1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>p[i].x>>p[i].y;
		}
		memset(path,0,sizeof path);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j){
					path[i][j]=1<<j;		
				}else{
					double x1=p[i].x,x2=p[j].x,y1=p[i].y,y2=p[j].y;
					if(!cmp(x1,x2)){
						continue;
					}
					double a=(y1/x1-y2/x2)/(x1-x2);
					if(cmp(a,0)>=0){
						continue;
					}
					double b=y1/x1-a*x1;
					int st=0;
					for(int k=0;k<n;k++){
						double xx=p[k].x,yy=p[k].y;
						if(!cmp(xx*xx*a+b*xx,yy)){
							st+=1<<k;
						}
					}
					path[i][j]=st;
				}
			}
		}	
		memset(f,0x3f,sizeof f);
		f[0]=0;
		for(int i=0;i+1<1<<n;i++){
			int x=0;
			for(int j=0;j<n;j++){
				if(!(i>>j&1)){
					x=j;
					break;
				}
			}
			for(int j=0;j<n;j++){
				f[i|path[x][j]]=min(f[i|path[x][j]],f[i]+1);
			}
		}
		cout<<f[(1<<n)-1]<<endl;
	}
	
}
