#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int son[N][26],cnt[N],idx;
char str[N];
void insert(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }
    cnt[p]++;
}

int query(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u])return 0;
        else p=son[p][u];
    }
    return cnt[p];
}
int main(){
    int n;
    cin>>n;
    while(n--){
        char c;
        cin>>c;
        if(c=='I'){
            cin>>str;
            insert(str);
        }else {
            scanf("%s",str);
            cout<<query(str)<<endl;
        }
    }
}