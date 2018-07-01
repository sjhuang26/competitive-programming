/*
SPOJ
CERC07K
*/
#include<iostream>
#include<vector>
#include<queue>
#include<array>
#include<string>
#include<tuple>
using namespace std;
string a[100];
int d[16][100][100];
const string ks="BYRG";
const string ks2="byrg";
int main(){
    while(true){
        //cout<<"NEWCASE\n";
        int R,C,ir,ic;cin>>R>>C;
        array<vector<pair<int,int>>,4>dr;
        if(0==R&&0==C)break;
        for(int i=0;i<R;++i){
            cin>>a[i];
            for(int j=0;j<C;++j){
                for(int k=0;k<16;++k)d[k][i][j]=-1;
                if(a[i][j]=='*')ir=i,ic=j,a[i][j]='.';
            }
        }
        queue<tuple<int,int,int,int>>q;//r c key d
        bool wr=0;int wrd,D=0;
        q.push({ir,ic,0,0});
        while(!q.empty()){
            auto rw=q.front();q.pop();
            int r=get<0>(rw),c=get<1>(rw),kv=get<2>(rw),da=get<3>(rw);
            //cout<<r<<' '<<c<<' '<<kv<<'\n';
            if(0>r||r>=R||0>c||c>=C||d[kv][r][c]!=-1)continue;
            char v=a[r][c];
            if(v=='#')continue;
            if(v=='X'){
                wr=1;
                wrd=da;
                break;
            }else{
                d[kv][r][c]=da;
                int ki=ks2.find(v),di=ks.find(v);
                if(ki!=string::npos){
                    q.push({r,c,(kv|(1<<ki)),da});
                }
                if(di!=string::npos&&(kv&(1<<di))==0)continue;
                q.push({r-1,c,kv,da+1});
                q.push({r+1,c,kv,da+1});
                q.push({r,c-1,kv,da+1});
                q.push({r,c+1,kv,da+1});
            }
        }
        if(wr){
            cout<<"Escape possible in "+to_string(wrd)+" steps.\n";
        }else{
            cout<<"The poor student is trapped!\n";
        }
    }
    return 0;
}