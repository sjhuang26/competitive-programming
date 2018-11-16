/*
Codeforces
450D
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    int V,E,T;cin>>V>>E>>T;
    vector<vector<pair<int,int>>>g(V);
    for(int i=0;i<E;++i){
        int u,v,w;cin>>u>>v>>w;--u;--v;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<pair<int,int>>gt;
    for(int i=0;i<T;++i){
        int v,w;cin>>v>>w;--v;
        g[0].push_back({v,w});
        g[v].push_back({0,w});
        gt.push_back({v,w});
    }
    vector<ll>d(V,1e18);
    d[0]=0;
    set<pair<ll,int>>q;//d v
    q.insert({d[0],0});
    while(!q.empty()){
        auto ur=q.begin();
        int u=ur->second;
        q.erase(ur);
        for(pair<int,int>vr:g[u]){
            int v=vr.first,w=vr.second;
            if(d[u]+w<d[v]){
                auto aux=q.find({d[v],v});
                if(aux!=q.end())q.erase(aux);
                d[v]=d[u]+w;
                q.insert({d[v],v});
            }
        }
    }
    //for(int i=0;i<V;++i)cout<<d[i]<<' ';cout<<endl;
    vector<int>ind(V);
    for(int i=0;i<V;++i){
        for(pair<int,int>j:g[i]){
            if(d[i]+j.second==d[j.first]){
                ++ind[j.first];
            }
        }
    }
    int r=0;
    for(pair<int,int>i:gt){
        if(d[i.first]==i.second){
            if(ind[i.first]>1){
                --ind[i.first];
                ++r;
            }
        }else ++r;
    }
    cout<<r<<'\n';
    return 0;
}
