/*
ID: sjhuang1
PROG: msquare
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    freopen("msquare.in","r",stdin);
    freopen("msquare.out","w",stdout);
    string ta="";
    for(int i=0;i<8;++i){
        int k;cin>>k;ta+=to_string(k);
    }
    //cout<<ta<<endl;
    queue<pair<string,string>>q;
    set<string>f;
    q.push({"12345678",""});
    f.insert("12345678");
    while(true){
        int Q=q.size();
        for(int t=0;t<Q;++t){
            pair<string,string> x=q.front();
            string a=x.first,p=x.second;
            q.pop();
            //cout<<a<<endl;
            if(a==ta){
                cout<<p.size()<<'\n'<<p<<'\n';
                return 0;
            }
            string w=string()+a[7]+a[6]+a[5]+a[4]+a[3]+a[2]+a[1]+a[0];
            string e=string()+a[3]+a[0]+a[1]+a[2]+a[5]+a[6]+a[7]+a[4];
            string r=string()+a[0]+a[6]+a[1]+a[3]+a[4]+a[2]+a[5]+a[7];
            //cout<<"W="<<w<<endl;
            //cout<<"W="<<a<<endl;
            //cout<<f.size()<<endl;
            if(f.find(w)==f.end())q.push({w,p+'A'}),f.insert(w);
            if(f.find(e)==f.end())q.push({e,p+'B'}),f.insert(e);
            if(f.find(r)==f.end())q.push({r,p+'C'}),f.insert(r);
        }
    }
    return 0;
}