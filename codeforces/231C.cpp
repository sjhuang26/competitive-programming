/*
Codeforces
231C
*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int N,K,a[100000],r=-1,rn=-1,g=0;
ll c=0;
int main(){
    cin>>N>>K;
    for(int i=0;i<N;++i)cin>>a[i];
    sort(a,a+N);
    for(int i=0;;++i){
        if(i-g+1>r)r=i-g+1,rn=a[i];
        if(i==N-1)break;
        int d=a[i+1]-a[i];
        c+=(ll)d*(i-g+1);
        //cout<<'c'<<c<<'\n';
        while(c>K){
            c-=a[i+1]-a[g];
            ++g;
        }
    }
    // cout<<r<<' '<<rn<<'\n';
    cout<<r<<' '<<rn<<'\n';
}
