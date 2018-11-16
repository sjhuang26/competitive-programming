/*
ID: sjhuang1
PROG: kimbits
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
int N,L;ll I;
ll d[32][32]={};
ll r(int l,int b){
    //cout<<l<<' '<<b<<'\n';
    if(0>l||0>b)return 0;
    if(d[l][b]!=-1)return d[l][b];
    ll x=l==0?1:r(l-1,b-1)+r(l-1,b);
    d[l][b]=x;
    return x;
}
int main(){
    freopen("kimbits.in","r",stdin);
    freopen("kimbits.out","w",stdout);
    cin>>N>>L>>I;
    for(int i=0;i<32;++i)for(int j=0;j<32;++j)d[i][j]=-1;
    r(N,L);
    /*for(int i=0;i<=N;++i){
        for(int j=0;j<=N;++j)cout<<d[i][j]<<' ';
        cout<<'\n';
    }*/
    string r="";
    ll s=I;int b=L;
    for(int i=N;i>0;--i){
        ll p=d[i-1][b];
        if(s<=p){
            r+='0';
        }else{
            r+='1';
            s-=p;
            --b;
        }
    }
    cout<<r<<'\n';
    return 0;
}