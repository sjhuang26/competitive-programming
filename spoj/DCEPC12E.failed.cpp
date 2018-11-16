/*
SPOJ
DCEPC12E
*/
#include<iostream>
using namespace std;
typedef long long ll;
ll a[100][100],b[100][100],sa[100]={},sb[100]={};
int main(){
    int N,T;cin>>N;ll r=0;
    for(int i=0;i<N;++i)for(int j=0;j<N;++j)cin>>a[i][j],sa[j]+=a[i][j];
    for(int i=0;i<N;++i)for(int j=0;j<N;++j)cin>>b[i][j],sb[i]+=b[i][j];
    for(int i=0;i<N;++i)for(int j=0;j<N;++j)for(int k=0;k<N;++k)r+=a[i][k]*b[k][j];
    cin>>T;
    for(int t=0;t<T;++t){
        //cout<<r<<'\n';
        char x;int i,j;ll k;cin>>x>>i>>j>>k;
        if(x=='A'){
            r+=(k-a[i][j])*sb[j];
        }else{
            r+=(k-b[i][j])*sa[i];
        }
        cout<<r<<'\n';
    }
}
