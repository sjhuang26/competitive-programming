/*
Codeforces
742D
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int N,M,W;cin>>N>>M>>W;
    int c[1000],a[1000];
    bool f[1000];
    for(int i=0;i<N;++i)cin>>c[i],f[i]=0;
    for(int i=0;i<N;++i)cin>>a[i];
    vector<vector<int>>g(N);
    for(int i=0;i<M;++i){
        int x,y;cin>>x>>y;--x;--y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int toc=0,toa=0,d1[1001]={},d2[1001]={};
    int*d=d1;int*dn=d2;
    for(int i=0;i<N;++i)if(!f[i]){
        toc=toa=0;
        vector<int>vals;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int u=q.front();q.pop();
            if(f[u])continue;
            vals.push_back(u);
            toc+=c[u];toa+=a[u];
            f[u]=1;
            for(int v:g[u])if(!f[v]){
                q.push(v);
            }
        }
        for(int j:vals){
            for(int i=c[j];i<=W;++i){
                if(d[i]+a[j]>dn[i-c[j]]){
                    dn[i-c[j]]=d[i]+a[j];
                }
            }
        }
        for(int i=toc;i<=W;++i)
            if(d[i]+toa>dn[i-toc])dn[i-toc]=d[i]+toa;
        //cout<<'V'<<vals.size()<<endl;
        //for(int i=0;i<=W;++i)cout<<dn[i]<<' ';cout<<endl;
        for(int i=0;i<=W;++i)d[i]=dn[i];
        int*ux=d;d=dn;dn=ux;
    }
    int r=0;
    for(int i=0;i<=W;++i)r=max(r,dn[i]);
    cout<<r<<'\n';
    return 0;
}
