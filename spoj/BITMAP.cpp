/*
SPOJ
BITMAP
*/
#include<iostream>
#include<queue>
using namespace std;
bool a[182][182];
int g[182][182];
int main(){
    int T,N,M;
    cin>>T;
    for(int t=0;t<T;++t){
        cin>>N>>M;
        queue<pair<int,int>>q;
        for(int i=0;i<N;++i){
            string x;cin>>x;
            for(int j=0;j<M;++j){
                a[i][j]=x[j]=='1';
                if(a[i][j]){
                    q.push({i,j});
                }
                g[i][j]=-1;
            }
        }
        int d=0;
        while(!q.empty()){
            int Q=q.size();
            for(int i=0;i<Q;++i){
                auto rw=q.front();q.pop();
                int r=rw.first,c=rw.second;
                if(0>r||r>=N||0>c||c>=M||g[r][c]!=-1)continue;
                g[r][c]=d;
                q.push({r+1,c});
                q.push({r,c+1});
                q.push({r-1,c});
                q.push({r,c-1});
            }
            ++d;
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                cout<<g[i][j];
                if(j!=M-1)cout<<' ';
            }
            cout<<'\n';
        }
    }
    return 0;
}
