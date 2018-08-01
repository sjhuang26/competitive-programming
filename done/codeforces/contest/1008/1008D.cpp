/*
Codeforces
1008D
(upsolved)
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
int dc(int n){
    int r=0;
    int b=(int)sqrt(n);
    //cout<<'i'<<b<<' '<<n<<endl;
    for(int i=1;i<=b;++i){
        if(n%i==0){
            if(n/i==i)++r;
            else r+=2;
        }
    }
    //cout<<nn<<'d'<<r<<endl;
    return r;
}
bool isw(int a,int b){
    return ((a&(1<<b))!=0);
}
bool val(int i,int j,int k){
    bool w=0;
    if(isw(i,0)&&isw(j,1)&&isw(k,2))w=1;
    if(isw(i,0)&&isw(k,1)&&isw(j,2))w=1;
    if(isw(j,0)&&isw(i,1)&&isw(k,2))w=1;
    if(isw(j,0)&&isw(k,1)&&isw(i,2))w=1;
    if(isw(k,0)&&isw(i,1)&&isw(j,2))w=1;
    if(isw(k,0)&&isw(j,1)&&isw(i,2))w=1;
    return w;
}
int main(){
    int T;cin>>T;
    for(int t=0;t<T;++t){
        int ar,br,cr;cin>>ar>>br>>cr;
        ll abc=dc(__gcd(__gcd(ar,br),cr));
        ll abr=dc(__gcd(ar,br));
        ll acr=dc(__gcd(ar,cr));
        ll bcr=dc(__gcd(br,cr));
        ll ab=abr-abc;
        ll ac=acr-abc;
        ll bc=bcr-abc;
        ll a=dc(ar)-abr-acr+abc;
        ll b=dc(br)-bcr-abr+abc;
        //cout<<dc(cr)<<' '<<acr<<' '<<bcr<<' '<<abc<<endl;
        ll c=dc(cr)-acr-bcr+abc;
        ll mp[8]={0,c,b,bc,a,ac,ab,abc};
        ll r=0;
        for(int i=1;i<8;++i){
            if(val(i,i,i)){
                if(mp[i]-2>0)r+=mp[i]*(mp[i]-1)*(mp[i]-2)/6;
                if(mp[i]-1>0)r+=mp[i]*(mp[i]-1);
                if(mp[i]-0>0)r+=mp[i];
                //cout<<i<<' '<<r<<endl;
            }
        }
        for(int i=1;i<8;++i){
            for(int j=1;j<8;++j){
                if(i!=j&&val(i,i,j)){
                    if(mp[i]-1>0)r+=mp[i]*(mp[i]-1)*mp[j]/2;
                    if(mp[i]-0>0)r+=mp[i]*mp[j];
                    //cout<<i<<' '<<j<<' '<<r<<endl;
                }
            }
        }
        for(int i=1;i<8;++i){
            for(int j=1;j<8;++j){
                for(int k=1;k<8;++k){
                    if(i<j&&j<k&&val(i,j,k)){
                        r+=mp[i]*mp[j]*mp[k];
                        //cout<<i<<' '<<j<<' '<<k<<' '<<r<<endl;
                    }
                }
            }
        }
        cout<<r<<'\n';
    }
}
