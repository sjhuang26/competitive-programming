/*
Codeforces
282
B
*/
#include<iostream>
using namespace std;
int a[1000000];
int main(){
    int N;cin>>N;
    for(int i=0;i<N;++i){
        int x,y;cin>>x>>y;
        a[i]=x;
    }
    string r="";
    int s=0;
    for(int i=0;i<N;++i){
        if(s+a[i]<=500){
            s+=a[i];
            r+='A';
        }else{
            s-=1000-a[i];
            r+='G';
        }
    }
    cout<<r<<'\n';
}