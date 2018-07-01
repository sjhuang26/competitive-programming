/*
Codeforces
714C
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int s[262144]={};//2^18
int main(){
    int T;cin>>T;
    for(int t=0;t<T;++t){
        string op;cin>>op;
        string a;cin>>a;
        if(op=="?"){
            int bi=0;
            int A=a.size();
            for(int i=0;i<A;++i){
                if(a[i]=='1')bi|=(1<<(A-1-i));
            }
            cout<<s[bi]<<'\n';
        }else{
            int bi=0;
            int A=a.size();
            for(int i=0;i<A;++i){
                if(((a[i]-'0')%2)==1){
                    bi|=(1<<(A-1-i));
                }
            }
            if(op=="+")++s[bi];
            else --s[bi];
        }
    }
    return 0;
}
