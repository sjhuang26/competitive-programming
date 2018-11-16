/*
ID: sjhuang1
PROG: contact
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct o{
    int n;
    int l;
    int f;
};
int main(){
    freopen("contact.in","r",stdin);
    freopen("contact.out","w",stdout);
    int A,B,N;cin>>A>>B>>N;
    string a="";
    while(true){
        string b;if(!(cin>>b))break;
        a+=b;
    }
    int as=a.size();
    int f[13][4096]={};
    vector<o>rw;
    for(int i=A;i<=B;++i){
        for(int j=0;j<=as-i;++j){
            int x=0,m=1;
            for(int k=j+i-1;k>=j;--k)x+=m*(a[k]=='1'?1:0),m*=2;
            ++f[i][x];
        }
        for(int j=0;j<4096;++j)if(f[i][j]!=0){
            o x;x.n=j;
            x.l=i;x.f=f[i][j];
            rw.push_back(x);
        }
    }
    sort(rw.begin(),rw.end(),[](const o&a,const o&b){
        return (a.f==b.f)?((a.l==b.l)?(a.n<b.n):(a.l<b.l)):(a.f>b.f);
    });
    int pf=1e9,tokp=false,inl=0,fc=0,i=0;
    while(true){
        if(i>=rw.size())break;
        o x=rw[i];
        bool first=false;
        if(pf!=x.f){
            ++fc;
            if(fc>N)break;
            if(tokp)cout<<'\n';
            inl=0;
            cout<<x.f<<'\n';
            first=true;
            tokp=true;
        }
        if(inl!=0&&inl%6==0)cout<<'\n',first=true;
        if(!first)cout<<' ';
        pf=x.f;
        string b="";
        //cout<<'['<<x.n<<']';
        for(int j=x.l-1;j>=0;--j)b+=(((x.n&(1<<j))!=0)?'1':'0');
        ++inl;
        cout<<b;
        ++i;
    }
    cout<<'\n';
    return 0;
}
