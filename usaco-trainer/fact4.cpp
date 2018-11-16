/*
ID: sjhuang1
PROG: fact4
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main(){
    freopen("fact4.in","r",stdin);
    freopen("fact4.out","w",stdout);
    int N;cin>>N;
    int lastd=1;
    int a=0,b=0;
    for(int i=1;i<=N;++i){
        int x=i;
        while(x%2==0)x/=2,++a;
        while(x%5==0)x/=5,++b;
        lastd=(lastd*x)%10;
    }
    if(a>b)for(int i=0;i<a-b;++i)lastd=(lastd*2)%10;
    if(b>a)for(int i=0;i<b-a;++i)lastd=(lastd*5)%10;
    cout<<lastd<<'\n';
    return 0;
}
