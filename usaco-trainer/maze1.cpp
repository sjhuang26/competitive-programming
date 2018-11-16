/*
ID: sjhuang1
PROG: maze1
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> ii;
int main(){
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    int R,C;
    cin>>C>>R>>ws;
    bool ah[101][38]={};
    bool av[100][39]={};
    for(int i=0;i<=R;++i){
        string a,b;
        getline(cin,a);
        if(i!=R)getline(cin,b);
        for(int j=0;j<C;++j){
            ah[i][j]=a[2*j+1]=='-';
        }
        if(i!=R){
            for(int j=0;j<C+1;++j){
                av[i][j]=b[2*j]=='|';
            }
        }
    }
    vector<ii>sp;
    for(int i=0;i<C;++i){
        if(!ah[0][i])sp.push_back(make_pair(0,i));
        if(!ah[R][i])sp.push_back(make_pair(R-1,i));
    }
    for(int i=0;i<R;++i){
        if(!av[i][0])sp.push_back(make_pair(i,0));
        if(!av[i][C])sp.push_back(make_pair(i,C-1));
    }
    queue<ii>q;
    int d[100][38]={};
    for(ii i:sp){
        q.push(i);
    }
    int dep=1;
    while(!q.empty()){
        int Q=q.size();
        for(int t=0;t<Q;++t){
            ii x=q.front();q.pop();
            int r=x.first,c=x.second;
            if(d[r][c]!=0)continue;
            if(!ah[r][c]&&r>0&&d[r-1][c]==0)q.push(make_pair(r-1,c));
            if(!ah[r+1][c]&&r+1<R&&d[r+1][c]==0)q.push(make_pair(r+1,c));
            if(!av[r][c]&&c>0&&d[r][c-1]==0)q.push(make_pair(r,c-1));
            if(!av[r][c+1]&&c+1<C&&d[r][c+1]==0)q.push(make_pair(r,c+1));
            d[r][c]=dep;
        }
        ++dep;
        /*for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            cout<<d[i][j]<<' ';
        }
        cout<<'\n';
    }*/
    }
    int res=0;
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            //cout<<d[i][j]<<' ';
            if(d[i][j]>res)res=d[i][j];
        }
        //cout<<'\n';
    }
    cout<<res<<'\n';
    return 0;
}