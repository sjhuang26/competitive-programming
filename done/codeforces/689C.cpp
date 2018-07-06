/*
Codeforces
689C
*/
#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll m;cin>>m;
    ll lo=0,hi=8*m+1,sol=-1,r=0;
    while(lo+1<hi){
        ll n=(lo+hi)>>1;
        r=0;
        for(ll i=2;;++i){
            ll inc=n/(i*i*i);
            if(inc==0)break;
            r+=inc;
        }
        //cout<<lo<<' '<<hi<<' '<<n<<endl;
        //cout<<r<<endl;
        if(r<m){
            lo=n;
        }else{
            hi=n;
            if(r==m)sol=n;
        }
    }
    cout<<sol<<'\n';
}
