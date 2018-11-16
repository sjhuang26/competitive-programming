/*
ID: sjhuang1
PROG: butter
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<set>
#include<vector>
using namespace std;
typedef pair<int,int>ii;
int main(){
    freopen("butter.in","r",stdin);
    freopen("butter.out","w",stdout);
    int N,P,C;cin>>N>>P>>C;//500 800
    int cps[500];for(int i=0;i<N;++i)cin>>cps[i],--cps[i];
    vector<ii>g[800];//to w
    for(int i=0;i<P;++i)g[i]=vector<ii>();
    for(int i=0;i<C;++i){
        int a,b,c;cin>>a>>b>>c;
        if(a==b)continue;
        g[a-1].push_back({b-1,c});
        g[b-1].push_back({a-1,c});
    }
    int best=1e9;
    for(int i=0;i<P;++i){
        set<ii>q;//d v
        int d[800];for(int j=0;j<P;++j)d[j]=1e9;
        d[i]=0;
        q.insert({d[i],i});
        while(!q.empty()){
            auto xx=q.begin();
            int x=xx->second;
            //cout<<':'<<x<<'\n';
            q.erase(xx);
            for(auto j:g[x]){
                if(d[j.first]>d[x]+j.second){
                    q.erase({d[j.first],j.first});
                    d[j.first]=d[x]+j.second;
                    q.insert({d[j.first],j.first});
                }
            }
        }
        int sum=0;
        for(int j=0;j<N;++j){
            if(d[cps[j]]==1e9){
                sum=1e9;
                break;
            }
            sum+=d[cps[j]];
        }
        if(sum<best)best=sum;
    }
    cout<<best<<'\n';
    return 0;
}
