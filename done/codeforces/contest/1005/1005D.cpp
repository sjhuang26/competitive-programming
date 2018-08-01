/*
Codeforces
1005D
(upsolved)
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
    cin>>ws;
    string a;cin>>a;
    int A=a.size();
    bool lmp[3]={},r=0;
    for(int i=0;i<A;++i){
        int x=a[i]-'0';
        if(x==0||x%3==0||lmp[3-x]){
            for(int i=0;i<3;++i)lmp[i]=0;
            ++r;
        }else{
            bool n[3]={};
            for(int i=0;i<3;++i){
                n[i]=lmp[(i+x)%3];
            }
            for(int i=0;i<3;++i){
                lmp[i]=n[i];
            }
        }
    }
    cout<<r<<'\n';
    return 0;
}
