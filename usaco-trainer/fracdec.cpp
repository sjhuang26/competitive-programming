/*
ID: sjhuang1
PROG: fracdec
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<string>
using namespace std;
int main(){
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    int n,d;cin>>n>>d;
    int cp=0;
    if(n>=d){
        cout<<n/d<<'.';
        cp+=to_string(n/d).length()+1;
    }else{
        cout<<"0.";
        cp+=2;
    }
    vector<int>ds,ss;
    set<int>sq;
    int s=10*(n%d);
    bool rep=false;
    while(true){
        if(sq.find(s)!=sq.end()){
            rep=true;
            break;
        }
        if(s==0)break;
        ds.push_back(s/d);
        sq.insert(s);
        ss.push_back(s);
        s=10*(s%d);
    }
    int S=ss.size();
    if(S==0)cout<<"0";
    //for(int i=0;i<S;++i)cout<<ds[i]<<' ';cout<<'\n';
    if(rep){
        int rs=S-1;
        while(ss[rs]!=s)--rs;
        for(int i=0;i<rs;++i){
            cout<<ds[i];
            ++cp;if(cp%76==0&&i!=S-1)cout<<'\n';
        }
        cout<<'(';++cp;
        if(cp%76==75)cout<<'\n';
        for(int i=rs;i<S;++i){
            cout<<ds[i];
            ++cp;if(cp%76==0&&i!=S-1)cout<<'\n';
        }
        cout<<")\n";
    }else{
        for(int i=0;i<S;++i){
            cout<<ds[i];
            ++cp;if(cp%76==0&&i!=S-1)cout<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}
