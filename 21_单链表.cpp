#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int head=-1,idx=0,e[N],ne[N];

void add_to_head(int x){
	e[idx]=x;
	ne[idx]=head;
	head=idx++;
}

void remove(int x){
	if(x==0){
		head=ne[head];
		return;
	}
	ne[x]=ne[ne[x]];

}

void insert(int x,int k){
	e[idx]=x;
	ne[idx]=ne[k];
	ne[k]=idx;
	idx++;
}
int main(){
	int m;cin>>m;
	while(m--){
		char c;
		cin>>c;
		switch(c){
			case 'H':
			{
				int x;
				cin>>x;
				add_to_head(x);
				break;
			}
			case 'D':{
				int k;cin>>k;
				remove(k-1);
				break;
			}
			case 'I':
			{
				int k,x;
				cin>>k>>x;
				insert(k,x);
				break;
			}
		}
	}
	int i=head;

	do{
		cout<<e[i]<<" ";
		i=ne[i];
	}while(ne[i]!=0);
}