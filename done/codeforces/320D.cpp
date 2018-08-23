/*
Codeforces
320D
*/
#include<stack>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[100000],t[100000];
int main(){
    int N;cin>>N;for(int i=0;i<N;++i)cin>>a[i];
    stack<int>s;
    for(int i=0;i<N;++i){
        //for(int i=0;i<N;++i)cout<<t[i]<<' ';cout<<endl;
        int x=1;
        while(!s.empty()&&a[s.top()]<a[i]){
            int y=t[s.top()];
            s.pop();
            x=max(x,y+1);
        }
        if(s.empty())t[i]=-1;
        else t[i]=x;
        s.push(i);
    }
    int r=0;
    for(int i=0;i<N;++i){
        r=max(r,t[i]);
    }
    cout<<r<<'\n';
    return 0;
}
