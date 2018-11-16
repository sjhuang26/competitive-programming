/*
Codeforces
313D
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll d[301][301];//n k
ll c[301][301];
int main(){
    int N,M,K;cin>>N>>M>>K;
    for(int i=0;i<=N;++i)for(int j=0;j<=N;++j)d[i][j]=1e18;
    for(int i=0;i<=N;++i)for(int j=0;j<=N;++j)c[i][j]=1e18;
    for(int i=0;i<M;++i){
        int u,v,x;cin>>u>>v>>x;--u;--v;
        for(int j=u;j<=v;++j){
            c[j][v+1]=min(c[j][v+1],(ll)x);
        }
    }
    for(int i=0;i<=N;++i)d[i][0]=0;
    for(int i=N-1;i>=0;--i)for(int j=0;j<=K;++j){
        d[i][j]=min(d[i][j],d[i+1][j]);
        for(int k=i+1;k<=N;++k){
            d[i][j]=min(d[i][j],c[i][k]+d[k][max(0,j-(k-i))]);
        }
    }
    cout<<(d[0][K]==1e18?-1:d[0][K])<<'\n';
    return 0;
}
