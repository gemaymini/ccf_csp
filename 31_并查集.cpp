#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int p[N];

void init(int n){
    for(int i=0;i<n;i++){
        p[i]=i;
    }
}

int find(int k){
    return p[k]==k?k:p[k]=find(p[k]);
}

void merge(int a,int b){
    int ra=find(a);
    int rb=find(b);
    if(ra==rb)return;
    else 
    {
        p[ra]=rb;
    }

}

int main(){
    int n,m;
    cin>>n>>m;
    init(n);
    for(int i=0;i<m;i++){
        char c;int a,b;
        cin>>c>>a>>b;
        if(c=='M'){
            merge(a,b);
        }else{
            if(find(a)==find(b)){
                cout<<"Yes"<<endl;
            }else cout<<"No"<<endl;
        }
    }
}