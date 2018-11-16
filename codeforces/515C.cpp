/*
Codeforces
515C
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int p[4][10]={{0,0,1,1,3,3,4,4,7,7},{0,0,0,1,1,1,2,2,2,4},{0,0,0,0,0,1,1,1,1,1},{0,0,0,0,0,0,0,1,1,1}};//2 3 5 7
int main(){
    int N;cin>>N;
    string a;cin>>a;
    int s[4]={};
    for(int i=0;i<N;++i){
        for(int j=0;j<4;++j){
            s[j]+=p[j][a[i]-'0'];
        }
    }
    string r="";
    for(int t=0;t<4;++t){
        //for(int i=0;i<4;++i)cout<<s[i]<<endl;
        char k="7532"[t];
        int I=s[3-t];
        for(int i=0;i<I;++i){
            r+=k;
            for(int j=0;j<4;++j)s[j]-=p[j][k-'0'];
        }
    }
    cout<<r<<'\n';
    return 0;
}