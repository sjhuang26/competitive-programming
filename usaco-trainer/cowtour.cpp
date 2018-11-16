/*
ID: sjhuang1
PROG: cowtour
LANG: C++11
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w",stdout);
    int P;cin>>P; //150
    int px[150],py[150];
    for(int i=0;i<P;++i){
        cin>>px[i]>>py[i];
    }
    double dr[150][150];
    double d[150][150];
    for(int i=0;i<P;++i){
        string x;cin>>x;
        for(int j=0;j<P;++j){
            if(x[j]=='1'||i==j){
                dr[i][j]=sqrt((px[j]-px[i])*(px[j]-px[i])+(py[j]-py[i])*(py[j]-py[i]));
            }else{
                dr[i][j]=1e9;
            }
            d[i][j]=dr[i][j];
        }
    }
    for(int k=0;k<P;++k){
        for(int i=0;i<P;++i){
            for(int j=0;j<P;++j){
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
    double fp[150];
    double fpi[150];
    for(int i=0;i<P;++i){
        double mx=-1,mxi=0;
        for(int j=0;j<P;++j){
            if(d[i][j]!=1e9&&d[i][j]>=mx)mx=d[i][j],mxi=j;
        }
        fp[i]=mx;
        fpi[i]=mxi;
    }
    //for(int i=0;i<P;++i)cout<<fpi[i]<<' ';cout<<'\n';
    double r=9e9;
    for(int i=0;i<P;++i)for(int j=0;j<P;++j){
        double ed=sqrt((px[j]-px[i])*(px[j]-px[i])+(py[j]-py[i])*(py[j]-py[i]));
        if(d[i][j]==1e9&&fp[i]+fp[j]+ed<=r){
            r=fp[i]+fp[j]+ed;
        }
    }
    for(int i=0;i<P;++i){
        if(fp[i]>r)r=fp[i];
    }
    cout<<std::setprecision(6)<<fixed<<r<<'\n';
    return 0;
}