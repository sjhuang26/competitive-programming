/*
Codeforces
1005B
(contest)
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
    cin>>ws;
    string a;cin>>a;
    cin>>ws;
    string b;cin>>b;
    int A=a.size(),B=b.size(),n=min(A,B);
    int rs=0;
    for(int i=0;i<n;++i){
        if(a[A-1-i]!=b[B-1-i])break;
        ++rs;
    }
    cout<<A+B-2*rs<<'\n';
    return 0;
}
