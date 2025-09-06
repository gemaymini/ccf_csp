#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct edge{
    int l,r;
    bool operator<(const edge &e)const{
        return l<e.l;
    }
};
edge e[N];
int h[N],idx;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        e[i]={l,r};
    }
    sort(e,e+n);
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=0;i<n;i++){
        if(q.empty()||q.top()>=e[i].l){
            q.push(e[i].r);
        }else{
            q.pop();
            q.push(e[i].r);
        }
    }
    cout<<q.size();
}

// #include <iostream>
// #include <algorithm>

// using namespace std;

// const int N = 100100;

// int n;
// int b[2 * N], idx;

// int main()
// {
//     scanf ("%d", &n);
//     for(int i = 0; i < n; i ++)
//     {
//         int l, r;
//         scanf("%d %d", &l, &r);
//         b[idx ++] = l * 2;//标记左端点为偶数。
//         b[idx ++] = r * 2 + 1;// 标记右端点为奇数。
//     }

//     sort(b, b + idx);

//     int res = 1, t = 0;
//     for(int i = 0; i < idx; i ++)
//     {
//         if(b[i] % 2 == 0) t ++;
//         else t --;
//         res = max(res, t);
//     }
//     printf ("%d\n", res);
//     return 0;
// // }