/*
Codeforces
1005C
(contest)
*/
#include<iostream>
#include<map>
using namespace std;
int main(){
    int A;cin>>A;
    int e[31];
    e[0]=1;
    for(int i=1;i<=30;++i){
        e[i]=e[i-1]*2;
    }
    map<int,int>a;
    for(int i=0;i<A;++i){
        int x;cin>>x;
        if(a.find(x)==a.end()){
            a[x]=1;
        }else{
            ++a[x];
        }
    }
    int r=0;
    for(auto it=a.begin();it!=a.end();++it){
        int x=it->first,t=it->second;
        bool w=0;
        for(int i=0;i<=30;++i)if(a.find(e[i]-x)!=a.end()&&(e[i]-x!=x||a[e[i]-x]>1)){
            w=1;
            break;
        }
        if(!w){
            r+=t;
            //cout<<x<<' '<<t<<endl;
        }
    }
    cout<<r<<'\n';
    return 0;
}
