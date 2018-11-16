/*
Codeforces
281D
*/
#include<iostream>
#include<stack>
using namespace std;
int a[100000];
int main(){
    int N;cin>>N;
    for(int i=0;i<N;++i)cin>>a[i];
    stack<int>s;
    int r=-1;
    for(int i=0;i<N;++i){
        while(!s.empty()&&s.top()<a[i])s.pop();
        if(!s.empty()){
            if((s.top()^a[i])>r)r=(s.top()^a[i]);
        }
        s.push(a[i]);
    }
    while(!s.empty())s.pop();
    for(int i=N-1;i>=0;--i){
        while(!s.empty()&&s.top()<a[i])s.pop();
        if(!s.empty()){
            if((s.top()^a[i])>r)r=(s.top()^a[i]);
        }
        s.push(a[i]);
    }
    cout<<r<<'\n';
}
