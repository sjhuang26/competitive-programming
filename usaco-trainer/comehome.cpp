/*
ID: sjhuang1
PROG: comehome
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<set>
using namespace std;
typedef pair<int,int> ii;
bool iscap(char a){
    return 'A'<=a&&a<='Z';
}
bool islow(char a){
    return 'a'<=a&&a<='z';
}
int main(){
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);
    int Q;cin>>Q;
    bool cow[26]={};
    int g[52][52]={};
    for(int i=0;i<52;++i)for(int j=0;j<52;++j)g[i][j]=1e9;
    for(int i=0;i<Q;++i){
        char a,b;int c;
        cin>>a>>b>>c;
        if(iscap(a))cow[a-'A']=true;
        if(iscap(b))cow[b-'A']=true;
        int ai=(iscap(a)?a-'A'+26:a-'a'),bi=(iscap(b)?b-'A'+26:b-'a');
        g[ai][bi]=g[bi][ai]=min(g[ai][bi],c);
    }
    //for(int i=0;i<52;++i){for(int j=0;j<52;++j)cout<<g[i][j]<<' ';cout<<'\n';}
    cow[25]=false;
    int bestcow=5e8,besti=-1;
    for(int i=26;i<52;++i)if(cow[i-26]){
        //cout<<i<<"!\n";
        set<ii>q;
        int d[52]={};
        for(int j=0;j<52;++j)d[j]=1e9;
        q.insert({0,i});
        d[i]=0;
        while(!q.empty()){
            auto xp=q.begin();
            int x=xp->second;
            //cout<<x<<'\n';
            q.erase(xp);
            for(int j=0;j<52;++j)if(g[x][j]!=1e9&&d[j]>d[x]+g[x][j]){
                q.erase({d[j],j});
                d[j]=d[x]+g[x][j];
                q.insert({d[j],j});
            }
        }
        //cout<<d[51]<<"d\n";
        if(bestcow>d[51])bestcow=d[51],besti=i;
    }
    cout<<(char)('A'-26+besti)<<' '<<bestcow<<'\n';
}
