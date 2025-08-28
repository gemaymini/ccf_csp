#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int head,e[N],ne[N],idx;

void init(){
	head=-1;
	idx=0;
}

void add_to_head(int x){
	e[idx]=x;
	ne[idx]=head;
	head=idx++;
}

int main(){
	
}
