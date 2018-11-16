/*
SPOJ
CDC12_H
*/
#include<iostream>
using namespace std;
typedef long long ll;
ll g[300000];
ll lz[300000];
ll tget(int n,int x,int y,int a,int b){
    //cout<<"TGET"<<n<<' '<<x<<' '<<y<<' '<<a<<' '<<b<<endl;
    if(y<a||b<x||x>y)return 0;
    if(lz[n]!=0){
        g[n]+=lz[n]*(y-x+1);
        if(x!=y){
            lz[n*2]+=lz[n];
            lz[n*2+1]+=lz[n];
        }
        lz[n]=0;
    }
    if(a<=x&&y<=b){
        return g[n];
    }
    int md=(x+y)/2;
    return tget(2*n,x,md,a,b)+tget(2*n+1,md+1,y,a,b);
}
void tset(int n,int x,int y,int a,int b){
    //cout<<"TSET"<<n<<x<<y<<a<<b<<endl;
    if(lz[n]!=0){
        g[n]+=lz[n]*(y-x+1);
        if(x!=y){
            lz[n*2]+=lz[n];
            lz[n*2+1]+=lz[n];
        }
        lz[n]=0;
    }
    if(y<a||b<x||x>y)return;
    if(a<=x&&y<=b){
        //lz[n]+=1;
        g[n]+=y-x+1;
        if(x!=y){
            lz[n*2]+=1;
            lz[n*2+1]+=1;
        }
        return;
    }
    int md=(x+y)/2;
    //cout<<"REC"<<endl;
    tset(2*n,x,md,a,b);tset(2*n+1,md+1,y,a,b);
    g[n]=g[2*n]+g[2*n+1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    for(int t=0;t<T;++t){
        int N,Q,P=1;cin>>N>>Q;
        while(P<N)P*=2;
        for(int i=0;i<2*P;++i)g[i]=0,lz[i]=0;
        cout<<"Scenario #"<<(t+1)<<":\n";
        for(int q=0;q<Q;++q){
            string x;int y,z;cin>>x>>y>>z;--y;--z;
            //cout<<"TREE=";
                //for(int i=0;i<2*P;++i)cout<<g[i]<<' ';
                //cout<<endl;
                //cout<<"LZ=";
                //for(int i=0;i<2*P;++i)cout<<lz[i]<<' ';
                //cout<<endl;
            if(x=="modification"){
                tset(1,0,P-1,y,z);
                cout<<"OK\n";
            }else if(x=="answer"){
                cout<<tget(1,0,P-1,y,z)<<'\n';
            }
        }
    }
    return 0;
}
