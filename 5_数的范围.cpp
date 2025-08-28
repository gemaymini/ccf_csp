#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int p[N];
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)scanf("%d",&p[i]);
    while(q--){
        int x;
        cin>>x;
        int l1=-1,r1=n;
        while(l1+1!=r1){
            int mid=(l1+r1)>>1;
            if(p[mid]<=x)l1=mid;
            else r1=mid;
        }
        // l1
        if(p[l1]!=x){
            cout<<"-1 -1"<<endl;
        }else{
            int l2=-1,r2=n;
            while(l2+1!=r2){
                int mid = (l2+r2)>>1;
                if(p[mid]>=x)r2=mid;
                else l2=mid;
            }
            cout<<r2<<" "<<l1<<endl;
        }
    }

}