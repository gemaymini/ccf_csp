#include<bits/stdc++.h>
using namespace std;

stack<int>n;
stack<char>op;
map<char,int>h{{'+',1},{'-',1},{'*',2},{'/',2}};

void eval(){
    int num1=n.top();
    n.pop();
    int num2=n.top();
    n.pop();
    char c=op.top();
    op.pop
    if(c=='+'){
        n.push(num1+num2);
    }else if(c=='-'){
        n.push(-num1+num2);
    }else if(c=='*'){
        n.push(num1*num2);
    }else if(c=='/'){
        n.push(num2/num1);
    }
}
int main(){
    string s;cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            int num=0,j=i;
            while(j<s.size()&&isdigit(s[j])){
                num=num*10+s[j]-'0';
                j++;
            }
            n.push(num);
            i=j-1;
        }else if(s[i]=='('){
            op.push('(');
        }else if(s[i]==')'){
            while(op.top()!='('){
                eval();
            }
            op.pop();
        }else{
            while(op.size()&&h[op.top()]>=h[s[i]]){
                eval();
            }
            op.push(s[i]);
            
        }
    }
    while(op.size()){
        eval();
    }
    cout<<n.top();
}