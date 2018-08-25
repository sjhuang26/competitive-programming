/*
Codeforces
437D
(failed)
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;
int p[100000],a[100000],s[100000],am[100000];
vector<vector<int>>g;
vector<pair<int,int>>as;
int stp(int n){
    return p[n]==n?n:p[n]=stp(p[n]);
}
void un(int a,int b){
    a=stp(a);b=stp(b);
    if(a!=b){
        if(s[a]>s[b]){
            p[b]=a;
            s[a]+=s[b];
        }else{
            p[a]=b;
            s[b]+=s[a];
        }
    }
}
int main(){
    int V,E;cin>>V>>E;
    for(int i=0;i<V;++i){
        int x;cin>>x;
        as.push_back({-x,i});
        p[i]=i;
        s[i]=1;
    }//cout<<'@'<<endl;
    g=vector<vector<int>>(V);
    sort(as.begin(),as.end());
    for(int i=0;i<V;++i){
        am[as[i].second]=i;
        a[i]=(-as[i].first);
    }//cout<<'@'<<endl;
    //cout<<'E'<<E<<endl;
    for(int i=0;i<E;++i){
        int u,v;cin>>u>>v;--u;--v;
        u=am[u];v=am[v];
        //cout<<u<<' '<<v<<endl;
        if(u>v)g[u].push_back(v);
        else g[v].push_back(u);
    }//cout<<'@'<<endl;
    ll r=0;
    for(int i=0;i<V;++i){
        ll sm=0;
        ll ssm=0;
        for(int j:g[i]){
            int x=stp(j);
            if(x!=stp(i))sm+=s[x],ssm+=s[x]*s[x];
            un(i,j);
        }
        r+=a[i]*sm;
        r+=a[i]*(sm*sm-ssm)/2;
        //cout<<r<<endl;
    }//cout<<'@'<<endl;
    cout<<fixed<<setprecision(6)<<(r*1.0)/((ll)V*(V-1)/2)<<'\n';
    return 0;
}
