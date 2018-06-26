/*
Codeforces
416
C
*/
#include<iostream>
#include<algorithm>
#include<array>
using namespace std;
int main(){
    int N;cin>>N;
    int c[1000],p[1000];
    bool rf[1000]={};
    for(int i=0;i<N;++i)cin>>c[i]>>p[i];
    int K;cin>>K;
    array<pair<int,int>,1000>k;//size index
    for(int i=0;i<K;++i){
        int x;cin>>x;k[i]=make_pair(x,i);
    }
    //cout<<k[0].first<<endl;
    sort(k.begin(),k.begin()+K);
    //cout<<k[0].first<<endl;
    int ar[1000],at[1000],R=0,S=0;
    //for(int i=0;i<K;++i)cout<<k[i]<<' ';
    for(int i=0;i<K;++i){
        int b=-1,bi=-1;
        for(int j=0;j<N;++j){
            if(!rf[j]&&c[j]<=k[i].first&&p[j]>=b){
                b=p[j];
                bi=j;
            }
        }
        if(bi!=-1){
            ar[R]=bi+1;
            at[R]=k[i].second+1;
            rf[bi]=true;
            ++R;
            S+=b;
        }
    }
    cout<<R<<' '<<S<<'\n';
    for(int i=0;i<R;++i){
        cout<<ar[i]<<' '<<at[i]<<'\n';
    }
    return 0;
}