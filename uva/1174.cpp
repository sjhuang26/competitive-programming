/*
UVa
1174
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
int main(){
    int T;cin>>T;
    for(int t=0;t<T;++t){
        int V;cin>>V;
        vector<vector<pair<int,int>>>g(V);//vtx wt
        map<string,int>m;
        int E;cin>>E;
        int va=0;
        for(int i=0;i<E;++i){
            string a,b;int c;
            cin>>a>>b>>c;
            int x,y;
            if(m.find(a)==m.end())m[a]=va++,x=va-1;
            else x=m[a];
            if(m.find(b)==m.end())m[b]=va++,y=va-1;
            else y=m[b];
            g[x].push_back({y,c});
            g[y].push_back({x,c});
        }
        vector<int>d(V,1e9);
        vector<int>e(V,0);
        vector<bool>f(V);
        set<pair<int,int>>q;
        d[0]=0;
        q.insert({d[0],0});
        int cost=0;
        while(!q.empty()){
            auto x=q.begin();
            int w=x->second;
            //cout<<e[w]<<endl;
            q.erase(x);
            f[w]=true;
            cost+=e[w];
            for(auto i:g[w]){
                //cout<<i.first<<endl;
                //cout<<d[w]+i.second<<endl;
                if(!f[i.first]&&d[i.first]>i.second){
                    q.erase({d[i.first],i.first});
                    d[i.first]=i.second;
                    e[i.first]=i.second;
                    q.insert({d[i.first],i.first});
                }
            }
        }
        cout<<cost<<'\n';
        if(t!=T-1)cout<<'\n';
    }
    return 0;
}
