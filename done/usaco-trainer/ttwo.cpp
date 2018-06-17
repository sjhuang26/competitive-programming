/*
ID: sjhuang1
PROG: ttwo
LANG: C++11
*/
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<tuple>
using namespace std;
string a[10];
int dy[4]={0,1,0,-1};
int dx[4]={-1,0,1,0};
tuple<int,int,int> state(int x,int y,int d){
    int ao=x+dx[d],b=y+dy[d];
    if(ao<0||ao>9||b<0||b>9||a[ao][b]=='*'){
        return make_tuple(x,y,(d+1)%4);
    }else{
        return make_tuple(ao,b,d);
    }
}
int main(){
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w",stdout);
    for(int i=0;i<10;++i){
        cin>>a[i];
    }
    int cx,cy,cd=0,fx,fy,fd=0;
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            if(a[i][j]=='C')cx=i,cy=j,a[i][j]='.';
            if(a[i][j]=='F')fx=i,fy=j,a[i][j]='.';
        }
    }
    int tt=0;
    for(int t=0;t<400*401;++t){
        //cout<<cx<<" "<<cy<<" "<<cd<<"\n";
        tie(cx,cy,cd)=state(cx,cy,cd);
        tie(fx,fy,fd)=state(fx,fy,fd);
        if(cx==fx&&cy==fy){
            tt=t+1;break;
        }
    }
    cout<<tt<<'\n';
    return 0;
}
