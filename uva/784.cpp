/*
UVa
784
*/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int main(){
    int T;cin>>T;
    for(int t=0;t<T;++t){
        vector<string>a;
        while(true){
            string x;
            getline(cin,x);
            if(x=="")continue;
            a.push_back(x);
            if(x[0]=='_')break;
        }
        int A=a.size();
        pair<int,int>sr;
        for(int i=0;i<A;++i){
            int B=a[i].size();
            for(int j=0;j<B;++j){
                if(a[i][j]=='*')sr={i,j};
            }
        }
        queue<pair<int,int>>q;
        set<pair<int,int>>f;
        q.push(sr);
        while(!q.empty()){
            auto w=q.front();
            q.pop();
            int r=w.first,c=w.second;
            if(f.find({r,c})!=f.end())continue;
            //cout<<"Q="<<r<<' '<<c<<'\n';
            f.insert({r,c});
            for(int i=-1;i<=1;++i){
                for(int j=-1;j<=1;++j){
                    a[r+i][c+j]='#';
                }
            }
            if(a[r-2][c]==' '){
                a[r-2][c]='#';
                q.push({r-4,c});
            }
            if(a[r+2][c]==' '){
                a[r+2][c]='#';
                q.push({r+4,c});
            }
            if(a[r][c-2]==' '){
                a[r][c-2]='#';
                q.push({r,c-4});
            }
            if(a[r][c+2]==' '){
                a[r][c+2]='#';
                q.push({r,c+4});
            }
        }
        for(int i=0;i<A;++i){
            cout<<a[i]<<'\n';
        }
    }
    return 0;
}
