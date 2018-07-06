/*
Codeforces
466C
*/
#include<iostream>
using namespace std;
typedef long long ll;
int A,a[500000],b[500000],ba=0;
ll S=0,s=0,r=0;
int main(){
    cin>>A;
    for(int i=0;i<A;++i)cin>>a[i],S+=a[i];
    if(S%3!=0){
        cout<<"0\n";
        return 0;
    }
    S/=3;
    for(int i=A-1;i>=0;--i){
        s+=a[i];
        if(s==S)++ba;
        b[i]=ba;
    }
    s=0;
    for(int i=0;i<A-2;++i){
        s+=a[i];
        if(s==S){
            r+=b[i+2];
        }
    }
    cout<<r<<'\n';
    return 0;
}
