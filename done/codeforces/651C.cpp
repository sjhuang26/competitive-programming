/*
Codeforces
651C
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>ii;
typedef long long ll;
int main(){
    int N;cin>>N;
    vector<ii>a;
    for(int i=0;i<N;++i){
        int x,y;cin>>x>>y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end(),[](const auto&a,const auto&b){
        return a.first==b.first?a.second<b.second:a.first<b.first;
    });
    ll res=0;
    int px=2e9,py=2e9,bl=0;
    for(auto i:a){
        if(i.first==px)++bl;
        else{
            if(bl>0)res+=(ll)bl*(bl-1)/2;
            bl=1;
        }
        px=i.first;
        py=i.second;
    }
    if(bl>0)res+=(ll)bl*(bl-1)/2;
    bl=0;
    sort(a.begin(),a.end(),[](const auto&a,const auto&b){
        return a.second==b.second?a.first<b.first:a.second<b.second;
    });
    px=2e9;py=2e9;
    for(auto i:a){
        if(i.second==py)++bl;
        else{
            if(bl>0)res+=(ll)bl*(bl-1)/2;
            bl=1;
        }
        px=i.first;
        py=i.second;
    }
    if(bl>0)res+=(ll)bl*(bl-1)/2;
    bl=0;
    px=2e9;py=2e9;
    for(auto i:a){
        if(i.second==py&&i.first==px)++bl;
        else{
            if(bl>0)res-=(ll)bl*(bl-1)/2;
            bl=1;
        }
        px=i.first;
        py=i.second;
    }
    if(bl>0)res-=(ll)bl*(bl-1)/2;
    bl=0;
    cout<<res<<'\n';
}
