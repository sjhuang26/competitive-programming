/*
ID: sjhuang1
PROG: spin
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main(){
    freopen("spin.in","r",stdin);
    freopen("spin.out","w",stdout);
    bool s[5][360]={};//open?
    int rs[5]={};
    for(int i=0;i<5;++i){
        int a;cin>>rs[i]>>a;
        for(int j=0;j<a;++j){
            int b,c;cin>>b>>c;
            c=b+c;
            if(b>c)c+=360;
            for(int k=b;k<=c;++k)s[i][k%360]=1;
        }
    }
    /*for(int i=0;i<5;++i){
        for(int j=0;j<360;++j)cout<<s[i][j]<<' ';
        cout<<endl;
    }*/
    int p[5]={};
    for(int t=0;t<360;++t){
        for(int j=0;j<360;++j){
            bool iso=true;
            for(int i=0;i<5;++i)if(!s[i][(p[i]+j)%360])iso=false;
            if(iso){
                cout<<t<<'\n';
                return 0;
            }
        }
        for(int i=0;i<5;++i)p[i]=(p[i]-rs[i]+360)%360;
    }
    cout<<"none\n";
    return 0;
}
