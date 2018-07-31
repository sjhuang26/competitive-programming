/*
Codeforces
548D
*/
#include<iostream>
#include<stack>
using namespace std;
int r[200000],a[200000],d[200000];
int main(){
    int N;cin>>N;
    for(int i=0;i<N;++i)cin>>a[i],d[i]=0,r[i]=0;
    stack<int>q;
    for(int i=0;i<N;++i){
        while(!q.empty()&&a[q.top()]>=a[i])q.pop();
        if(q.empty()){
            d[i]=-1;
        }else{
            d[i]=q.top();
        }
        q.push(i);
        //cout<<d[i]<<endl;
    }
    q=stack<int>();
    for(int i=N-1;i>=0;--i){
        while(!q.empty()&&a[q.top()]>=a[i])q.pop();
        if(q.empty()){
            d[i]=N-d[i]-1;
        }else{
            d[i]=q.top()-d[i]-1;
        }
        q.push(i);
        //cout<<d[i]<<endl;
        r[d[i]-1]=max(r[d[i]-1],a[i]);
    }
    int rm=0;
    for(int i=N-1;i>=0;--i){
        rm=max(rm,r[i]);
        r[i]=rm;
    }
    for(int i=0;i<N;++i){
        cout<<r[i];
        if(i!=N-1)cout<<' ';
    }
    cout<<'\n';
    return 0;
}
