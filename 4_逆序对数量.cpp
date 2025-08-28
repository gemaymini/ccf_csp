#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;

int q[N],temp[N];
int num=0;
void merge_sort(int q[],int l,int r){
    if(l>=r)return;
    int mid=(l+r)>>1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r){
        if(q[i]<=q[j])
            temp[k++]=q[i++];
        else{
            temp[k++]=q[j++];
            num+=mid-i+1;
        }
    }
    while(i<=mid)temp[k++]=q[i++];
    while(j<=r)temp[k++]=q[j++];
    for(int t=l;t<=r;t++)
        q[t]=temp[t];
}

signed main(){
    int n;
    scanf("%lld",&n);
    for(int i=0;i<n;i++)scanf("%lld",&q[i]);
    merge_sort(q,0,n-1);
    printf("%lld",num);
}