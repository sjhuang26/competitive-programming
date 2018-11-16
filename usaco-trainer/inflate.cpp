/*
ID: sjhuang1
PROG: inflate
LANG: C++11
*/
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w",stdout);
    int M,N;cin>>M>>N;
    int ap[10000],am[10000];
    for(int i=0;i<N;++i){
        cin>>ap[i]>>am[i];
    }
    int d[10001];
    for(int i=0;i<=M;++i){
        int best=0;
        for(int j=0;j<N;++j)if(i-am[j]>=0&&d[i-am[j]]+ap[j]>best)best=d[i-am[j]]+ap[j];
        d[i]=best;
    }
    //for(int i=0;i<=M;++i)cout<<d[i];cout<<'\n';
    int res=0;
    for(int i=0;i<=M;++i){
        if(d[i]>res)res=d[i];
    }
    cout<<res<<'\n';
}
