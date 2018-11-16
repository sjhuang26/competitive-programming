/*
UVa
563
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct o{
    int u,v,c;
};
o mko(int u,int v,int c){
    o x;x.u=u;x.v=v;x.c=c;
    return x;
}
vector<vector<int>>g;
vector<o>ge;
int N,M,bk,V,T,L;
void edge(int u,int v,int c){
    g[u].push_back(ge.size());
    ge.push_back(mko(u,v,c));
}
void edgr(int u,int v){
    edge(u,v,1);
    edge(v,u,0);
}
void edg2(int a,int b,int c,int d){
    if(0>a||a>=N||0>c||c>=N||0>b||b>=M||0>d||d>=M)return;
    int u=L+a*M+b+1,v=c*M+d+1;
    edgr(u,v);
}
int main(){
    int TST;cin>>TST;
    while(TST--){ 
        //cout<<"----\n";
        cin>>N>>M>>bk;
        V=2*N*M+2;T=2*N*M+1;L=N*M;
        g=vector<vector<int>>(V);
        
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                //u to u'
                edgr(i*M+j+1,L+i*M+j+1);
                //edges to sink
                if(i==0||i==N-1||j==0||j==M-1){
                    edgr(L+i*M+j+1,T);
                }
                //TRBL
                edg2(i,j,i-1,j);
                edg2(i,j,i+1,j);
                edg2(i,j,i,j-1);
                edg2(i,j,i,j+1);
            }
        }
        //source to banks
        for(int i=0;i<bk;++i){
            int u,v;cin>>u>>v;
            u=N-u;--v;
            edgr(0,u*M+v+1);
        }
        int r=0;
        bool w=1;
        while(w){
            w=0;
            queue<int>q;
            q.push(0);
            vector<int>p(V,-1);
            while(!q.empty()){
                int u=q.front();q.pop();
                if(u==T){
                    w=1;
                    break;
                }
                for(int ei:g[u]){
                    o&e=ge[ei];
                    if(p[e.v]==-1&&e.c>0){
                        q.push(e.v);
                        p[e.v]=ei;
                    }
                }
            }
            if(w){
                int fl=1e9;
                //cout<<'=';
                for(int i=T;i!=0;i=ge[p[i]].u){
                    fl=min(fl,ge[p[i]].c);
                    //cout<<i<<' ';
                }
                //cout<<endl;
                for(int i=T;i!=0;i=ge[p[i]].u){
                    ge[p[i]].c-=fl;
                    ge[p[i]+1].c+=fl;
                }
                r+=fl;
            }
        }
        if(r==bk)cout<<"possible\n";
        else cout<<"not possible\n";
        //cout<<endl;
    }
    return 0;
}
