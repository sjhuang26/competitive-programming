/*
Codeforces
431D
*/
#include<iostream>
#include<bitset>
#include<string>
using namespace std;
typedef long long ll;
ll d[65][65];
int K;
ll f(ll x){
    string s=bitset<64>(x).to_string();
    ll r=0;
    int ka=K;
    for(int i=0;i<64;++i)if(s[i]=='1'){
        if(63-i<ka)break;
        r+=d[63-i][ka];
        --ka;
        if(ka==0)break;
    }
    //cout<<x<<' '<<r<<endl;
    return r;
}
int main(){
    ll lo=1,hi=1e18,md,M;
    cin>>M>>K;
    for(int i=1;i<=64;++i){
        for(int j=0;j<=i;++j){
            if(i==j||j==0)d[i][j]=1;
            else d[i][j]=d[i-1][j]+d[i-1][j-1];
        }
    }
    while(lo<=hi){
        md=(lo+hi)/2;
        string s=bitset<64>(md-1).to_string();
        ll r=f(md*2)-f(md);
        if(r==M){
            cout<<md<<'\n';
            return 0;
        }else if(r>M)hi=md-1;
        else lo=md+1;
    }
    //shouldn't happen
    return 1;
}
