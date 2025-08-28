#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N];

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    int j=0;
    for(int i=0;i<m&&j<n;i++){
    
        if(i>=j&&a[j]==b[i]){
            j++;

        }
    }
    if(j==n){
        cout<<"Yes";
    }else cout<<"No";
    
}