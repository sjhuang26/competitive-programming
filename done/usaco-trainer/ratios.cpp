/*
ID: sjhuang1
PROG: ratios
LANG: C++11
*/
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    freopen("ratios.in","r",stdin);
    freopen("ratios.out","w",stdout);
    int g[3],m[3][3];
    for(int i=0;i<3;++i)cin>>g[i];
    for(int i=0;i<3;++i)for(int j=0;j<3;++j)cin>>m[i][j];
    for(int i=0;i<100;++i){
        for(int j=0;j<100;++j){
            for(int k=0;k<100;++k){
                if(i==0&&j==0&&k==0)continue;
                int a=i*m[0][0]+j*m[1][0]+k*m[2][0];
                int a2=i*m[0][1]+j*m[1][1]+k*m[2][1];
                int a3=i*m[0][2]+j*m[1][2]+k*m[2][2];
                int f=a/g[0];
                if(f==0)continue;
                if(g[0]*f==a&&g[1]*f==a2&&g[2]*f==a3){
                    cout<<i<<' '<<j<<' '<<k<<' '<<f<<'\n';
                    return 0;
                }
            }
        }
    }
    cout<<"NONE\n";
    return 0;
}