/*
Algorithm practice
Segment tree: lazy propagation
Iteration 1
7/24/2018
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int>g,lz;
int N,P;
int tsum(int n,int x,int y,int a,int b){
    //cout<<n<<' '<<x<<' '<<y<<' '<<a<<' '<<b<<' '<<lz[n]<<endl;
    //cout<<'S';
    if(y<a||b<x)return 0;
    if(lz[n]!=0){
        g[n]+=(y-x+1)*lz[n];
        if(x!=y){
            lz[2*n]+=lz[n];
            lz[2*n+1]+=lz[n];
        }
        lz[n]=0;
    }
    if(a<=x&&y<=b)return g[n];
    int md=(x+y)/2;
    return tsum(n*2,x,md,a,b)+tsum(n*2+1,md+1,y,a,b);
}
void tupd(int n,int x,int y,int a,int b,int c){
    //cout<<n<<' '<<x<<' '<<y<<' '<<a<<' '<<b<<' '<<c<<endl;
    //cout<<'U';
    if(y<a||b<x)return;
    if(a<=x&&y<=b){
        lz[n]+=c;
        return;
    }
    g[n]+=min(abs(y-a)+1,abs(x-b)+1)*c;
    //cout<<"MIN"<<min(abs(y-a),abs(x-b))<<endl;
    int md=(x+y)/2;
    tupd(2*n,x,md,a,b,c);
    tupd(2*n+1,md+1,y,a,b,c);
}
int main(){
    int N;cin>>N;
    P=1;while(N>P)P*=2;
    g=vector<int>(P*2);
    lz=vector<int>(P*2);
    for(int i=0;i<N;++i)cin>>g[P+i];
    for(int i=P-1;i>0;--i){
        g[i]=g[2*i]+g[2*i+1];
    }
    int Q;cin>>Q;
    for(int t=0;t<Q;++t){
        char qr;int a,b;cin>>qr>>a>>b;--a;--b;
        if(qr=='s')cout<<tsum(1,0,P-1,a,b)<<'\n';
        if(qr=='u'){
            int c;cin>>c;
            tupd(1,0,P-1,a,b,c);
            cout<<"UPDATED\n";
        }
    }
    return 0;
}
