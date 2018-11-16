/*
UVa
10344
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const string S="+-*";
int o(int a,char b,int c){
    if(b=='+')return a+c;
    if(b=='-')return a-c;
    if(b=='*')return a*c;
    return -999;
}
int main(){
    while(1){
        int a[5];
        for(int i=0;i<5;++i){
            cin>>a[i];
        }
        if(a[0]==0)break;
        string r="Impossible\n";
        sort(a,a+5);
        do{
        for(char i:S)
        for(char j:S)
        for(char k:S)
        for(char l:S)
        if(o(o(o(o(a[0],i,a[1]),j,a[2]),k,a[3]),l,a[4])==23){
            r="Possible\n";
            goto fin;
        }/*else{
            cout<<'A'<<a[0]<<'B'<<a[1]<<endl;
            cout<<o(o(o(o(a[0],i,a[1]),j,a[2]),k,a[3]),l,a[4])<<endl;
        }*/
        }while(next_permutation(a,a+5));
        fin:
        cout<<r;
    }
    return 0;
}
