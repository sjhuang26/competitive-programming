/*
SPOJ
CHOCOLA
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int T;cin>>T;
    for(int t=0;t<T;++t){
        int X,Y,x[1000],y[1000];cin>>X>>Y;
        --X;--Y;
        for(int i=0;i<X;++i)cin>>x[i];
        for(int i=0;i<Y;++i)cin>>y[i];
        sort(x,x+X,greater<int>());
        sort(y,y+Y,greater<int>());
        int xp=1,yp=1,xt=0,yt=0,c=0;
        while(xt<X||yt<Y){
            bool isx;
            if(xt==X)isx=false;
            else if(yt==Y)isx=true;
            else isx=x[xt]>y[yt];
            if(isx){
                c+=xp*x[xt];
                ++xt;++yp;
            }else{
                c+=yp*y[yt];
                ++yt;++xp;
            }
            //cout<<c<<'\n';
        }
        cout<<c<<'\n';
    }
    return 0;
}
