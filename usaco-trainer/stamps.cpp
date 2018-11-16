/*
ID: sjhuang1
PROG: stamps
LANG: C++11
*/
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    freopen("stamps.in","r",stdin);
    freopen("stamps.out","w",stdout);
    int N,K,d[10000],a[50];
    cin>>K>>N;
    for(int i=0;i<N;++i)cin>>a[i];
    d[0]=0;
    for(int i=1;;++i){
        int m=1e9;
        for(int j=0;j<N;++j)if(i-a[j]>=0)m=min(d[(i-a[j]+10000)%10000]+1,m);
        //cout<<m<<' ';
        if(m>K){
            cout<<i-1<<'\n';
            return 0;
        }
        d[i%10000]=m;
    }
    return 0;
}
