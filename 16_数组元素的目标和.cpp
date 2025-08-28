#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int b[N];
int n,m,x;

void quick_sort(int q[],int l,int r){
    if(l>=r) return;
    int i=l-1,j=r+1,x=q[(i+j)>>1];
    while(i<j){
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}
int erfen_search(int b[],int x){
    int l=-1,r=m;
    while(l+1!=r){
        int mid=(l+r)>>1;
        if(b[mid]<x){
            l=mid;
        }else if(b[mid]>x){
            r=mid;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){
    cin>>n>>m>>x;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    quick_sort(b,0,m-1);
    for(int i=0;i<n;i++){
        int res=x-a[i];
        int idx=erfen_search(b,res);
        if(idx!=-1){
            cout<<i<<" "<<idx<<endl;
        }
    }
}
