/*
Codeforces
677A
*/
#include<iostream>
using namespace std;
int main(){
    int n,h,a[1000];
    cin>>n>>h;
    for(int i=0;i<n;++i)cin>>a[i];
    int r=0;
    for(int i=0;i<n;++i)r+=(a[i]>h)?2:1;
    cout<<r<<'\n';
    return 0;
}
