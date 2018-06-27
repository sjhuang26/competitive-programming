/*
UVa
105
*/
#include<iostream>
#include<vector>
using namespace std;
int s[10001]={};
int main(){
    while(true){
        int a,b,c;
        if(!(cin>>a))break;
        cin>>b>>c;
        for(int i=a;i<c;++i){
            if(b>s[i])s[i]=b;
        }
    }
    int pr=0;
    vector<int>r;
    for(int i=0;i<=10000;++i){
        if(s[i]!=pr){
            pr=s[i];
            r.push_back(i);
            r.push_back(s[i]);
        }
    }
    int R=r.size();
    for(int i=0;i<R;++i){
        cout<<r[i];
        if(i!=R-1)cout<<' ';
    }
    cout<<'\n';
    return 0;
}
