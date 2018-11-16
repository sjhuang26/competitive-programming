/*
SPOJ
PSYCHON
*/
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
const int X=10000001;
int sv[X]={},d[X]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //calc sieve
    vector<int>pr;
    for(int i=2;i<X;++i)if(!sv[i]){
        for(int j=i;j<=X;j+=i)sv[j]=i;
    }
    for(int i=2;i<X;++i){
        int x=i,r=0;
        while(x%sv[i]==0)x/=sv[i],++r;
        d[i]=d[x]+(r%2?-1:1);
    }
    int T;cin>>T;
    while(T--){
        int x;cin>>x;
        cout<<(d[x]>0?"Psycho Number":"Ordinary Number")<<'\n';
    }
    return 0;
}
