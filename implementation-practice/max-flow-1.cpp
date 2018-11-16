/*
Algorithm practice
Max flow
Iteration 1
8/15/2018
---
Adjacency lists are used as opposed to adjacency matrices, which makes for a
more difficult implementation.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct o{//dest cap flow rev isoriginal
    int a,b,c,d;
    bool e;
    o(int q,int r,int s,int t,bool u){
        a=q;b=r;c=s;d=t;e=u;
    }
};
int main(){
    int V,E,S,T;cin>>V>>E>>S>>T;--S;--T;
    vector<vector<o>>g(V,vector<o>());
    for(int i=0;i<E;++i){
        int u,v,x;cin>>u>>v>>x;--u;--v;
        g[u].push_back(o(v,x,0,g[v].size(),1));
        g[v].push_back(o(u,x,x,g[u].size()-1,0));
    }
    int r=0;
    while(1){
        //cout<<'='<<endl;
        queue<int>q;
        q.push(S);
        vector<int>prd(V,-1),pri(V);
        while(!q.empty()){
            int x=q.front();q.pop();
            for(int ix=0;ix<g[x].size();++ix){
                o i=g[x][ix];
                if(prd[i.a]==-1&&i.a!=S&&i.b>i.c){
                    prd[i.a]=x;
                    pri[i.a]=ix;
                    q.push(i.a);
                }
            }
        }
        //for(int i=0;i<V;++i)cout<<prd[i]<<' ';cout<<endl;
        if(prd[T]==-1){
            break;
        }else{
            int rn=1e9;
            for(int i=T;prd[i]!=-1;i=prd[i]){
                o x=g[prd[i]][pri[i]];
                //cout<<'r'<<rn<<endl;
                rn=min(rn,x.b-x.c);
            }
            for(int i=T;prd[i]!=-1;i=prd[i]){
                o&x=g[prd[i]][pri[i]];
                x.c+=rn;
                g[x.a][x.d].c-=rn;
            }
            r+=rn;
        }
    }
    cout<<r<<'\n';
    for(int i=0;i<V;++i){
        for(o j:g[i])if(j.e){
            cout<<i+1<<" --> "<<j.a+1<<": flow="<<j.c<<'\n';
        }
    }
    return 0;
}
