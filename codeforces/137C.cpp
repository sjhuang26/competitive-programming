/*
Codeforces
137C
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>ii;
int main(){
    int n;cin>>n;
    vector<ii>a;
    for(int i=0;i<n;++i){
        int x,y;cin>>x>>y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end(),[](const ii&a,const ii&b){
        return (a.first==b.first)?a.second<b.second:a.first<b.first;
    });
    int m=-1,mp=-1,p=-1;
    int A=a.size();
    int r=0;
    for(int i=0;i<A;++i){
        if(a[i].first!=p)m=mp,p=a[i].first;
        if(a[i].second>mp)mp=a[i].second;
        else if(a[i].second<=m)++r;
    }
    cout<<r<<'\n';
    return 0;
}
