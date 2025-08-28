#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int head,idx,e[N],ne[N];
void init(){
	head=-1;
	idx=0;
}
void insert(int k,int x){
	e[idx]=x;
	ne[idx]=ne[k];
	ne[k]=idx;
	idx++;
}

void add_head(int x){
	e[idx]=x;
	ne[idx]=head;
	head=idx++;
}

void remove(int k){
	ne[k]=ne[ne[k]];
}

int main(){
	int m;cin>>m;
	init();
	while(m--){
		char c;
		cin>>c;
		if(c=='H'){
			int x;cin>>x;
			add_head(x);
		}else if(c=='D'){
			int k;cin>>k;
			if(k==0)
				head=ne[head];
			else{
				remove(k-1);
			}
		}else{
			int k,x;cin>>k>>x;
			insert(k-1,x);
		}
	}
	for(int i=head;i!=-1;i=ne[i])cout<<e[i]<<" ";
}