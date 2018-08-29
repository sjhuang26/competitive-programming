/*
UVa
11159
(mistake)
*/
#include<iostream>
#include<stack>
using namespace std;
int a[100],b[100],sd=0,id=0,V;
stack<int>s;
vector<vector<int>>g;
vector<int>v,lw,si;
vector<bool>f;
void tarj(int u){
    v[u]=lw[u]=id;
    ++id;
    s.push(u);
    f[u]=1;
    for(int i:g[u]){
        if(v[i]==-1){
            tarj(i);
            lw[u]=min(lw[u],lw[i]);
        }else if(f[i]){
            lw[u]=min(lw[u],v[i]);
        }
    }
    if(lw[u]==v[u]){
        while(1){
            int x=s.pop();
            si[x]=sd;
            f[x]=0;
            if(x==u)break;
        }
        ++sd;
    }
}
int main(){
    int T;cin>>T;
    for(int t=0;t<T;++t){
        int N,M;cin>>N;
        for(int i=0;i<N;++i)cin>>a[i];
        cin>>M;
        //2SAT
        V=2*(N+M);
        g=vector<vector<int>>(V);//N M N' M', X = remove X in final answer
        v=vector<int>(V,-1);
        lw=vector<int>(V,-1);
        si=vector<int>(V,-1);
        f=vector<bool>(V);
        sd=id=0;
        for(int i=0;i<M;++i){
            cin>>b[i];
            for(int j=0;j<N;++j){
                if(b[i]%a[j]==0){
                    g[j+N+M].push_back(i+N);//N' -> M
                    g[i+N+M+N].push_back(j);//M' -> N
                }
            }
        }
        for(int i=0;i<V;++i){
            if(v[i]==-1)tarj(i);
        }
        int r=0;
        for(int i=0;i<N+M;++i){
            if(si[i]==)
        }
    }
}