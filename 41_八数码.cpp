#include<bits/stdc++.h>
using namespace std;

const int N=10;

string ed="12345678x";

map<string,int>d;
queue<string>q;

int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

void bfs(string x){
    q.push(x);
    d[x]=0;
    while(!q.empty()){
        string s=q.front();
        q.pop();
        if(s==ed){
            cout<<d[s];
            return;
        }
        int x_idx=s.find('x');
        int x_=x_idx/3,y_=x_idx%3;
        for(int i=0;i<4;i++){
            int tx=x_+dx[i],ty=y_+dy[i];
            if(tx>=0&&tx<3&&ty>=0&&ty<3){
                int t=tx*3+ty;
                string ss=s;
                swap(s[t],s[x_idx]);
                if(d.find(s)==d.end()){
                    d[s]=d[ss]+1;
                    q.push(s);
                }
                swap(s[t],s[x_idx]);
            }
        }
    
    }
    cout<<-1;
}

int main(){
    string st="";
    for(int i=0;i<9;i++){
        char c;
        cin>>c;
        st+=c;
    }
    // cout<<s;
    bfs(st);
}
