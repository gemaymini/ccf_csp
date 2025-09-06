#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int sum=0;
    int cen=n/2;
    for(int i=0;i<n;i++){
        sum+=abs(a[cen]-a[i]);
    }
    cout<<sum;

}