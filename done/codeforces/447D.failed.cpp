/*
Codeforces
447D
(failed)
*/
#include<iostream>
#include<set>
using namespace std;
typedef long long ll;
int main(){
    int N,M,K,P,a[1000]={},b[1000]={};cin>>N>>M>>K>>P;
    for(int i=0;i<N;++i)for(int j=0;j<M;++j){
        int x;cin>>x;
        a[i]+=x;
        b[j]+=x;
    }
    multiset<int>sa,sb;
    for(int i=0;i<N;++i)sa.insert(a[i]);
    for(int i=0;i<M;++i)sb.insert(b[i]);
    ll r=0;ll la=0,lb=0;
    for(int k=0;k<K;++k){
        int rma=*prev(sa.end());
        int rmb=*prev(sb.end());
        ll ma=(ll)rma-la;
        ll mb=(ll)rmb-lb;
        //cout<<ma<<' '<<mb<<'\n';
        if(ma>mb){
            r+=ma;
            sa.erase(sa.find(rma));
            lb+=P;
            sa.insert(rma-M*P);
        }else{
            r+=mb;
            sb.erase(sb.find(rmb));
            la+=P;
            sb.insert(rmb-N*P);
        }
    }
    cout<<r<<'\n';
    return 0;
}
