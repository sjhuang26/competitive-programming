/*
ID: sjhuang1
PROG: concom
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    freopen("concom.in","r",stdin);
    freopen("concom.out", "w", stdout);
    int T;cin>>T;
    int g[100][100]={};
    for(int i=0;i<T;++i){
        int a,b,c;cin>>a>>b>>c;
        g[a-1][b-1]+=c;
    }
    bool ic[100];
    int co[100];
    for(int i=0;i<100;++i){
        for(int j=0;j<100;++j)ic[j]=0,co[j]=0;
        ic[i]=1;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int x=q.front();q.pop();
            for(int j=0;j<100;++j){
                co[j]+=g[x][j];
                if(co[j]>50&&!ic[j])q.push(j),ic[j]=1;
            }
        }
        for(int j=0;j<100;++j)if(i!=j&&ic[j])cout<<i+1<<' '<<j+1<<'\n';
    }
    return 0;
}