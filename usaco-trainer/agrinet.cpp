/*
ID: sjhuang1
PROG: agrinet
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<set>
using namespace std;
typedef pair<int,int> ii;
int main(){
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    int V;cin>>V;//3-100
    int g[100][100];
    for(int i=0;i<V;++i)for(int j=0;j<V;++j)cin>>g[i][j];
    bool f[100]={};
    int p[100]={},d[100]={};
    for(int i=0;i<V;++i)d[i]=1e9;
    set<ii>q;
    long long mst=0;
    q.insert({0,0});
    while(!q.empty()){
        auto pt=q.begin();
        int x=pt->second;
        q.erase(pt);
        mst+=g[x][p[x]];
        f[x]=1;
        for(int i=0;i<V;++i)if(!f[i]&&d[i]>g[x][i]){
            q.erase({d[i],i});
            d[i]=g[x][i];
            p[i]=x;
            q.insert({d[i],i});
        }
    }
    cout<<mst<<'\n';
    return 0;
}
