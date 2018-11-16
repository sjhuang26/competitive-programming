/*
Codeforces
812C
*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[100000];
ll q[100000];
int main(){
    int N;ll S;cin>>N>>S;// e5 e9
    for(int i=0;i<N;++i)cin>>a[i];
    int hi=N,lo=0,ml=0,mid;
    ll st=0,rt=0;
    while(lo<=hi){
        mid=(lo+hi)/2;
        //cout<<mid;
        for(int i=0;i<N;++i){
            q[i]=(ll)a[i]+((ll)(i+1))*mid;
        }
        sort(q,q+N);
        st=0;
        for(int i=0;i<mid;++i)st+=q[i];
        if(st<=S){
            lo=mid+1;
            if(mid>ml)rt=st,ml=mid;
        }else{
            hi=mid-1;
        }
    }
    cout<<ml<<' '<<rt<<'\n';
    return 0;
}
