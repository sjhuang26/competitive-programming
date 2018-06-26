/*
Codeforces
276
B
*/
#include<iostream>
using namespace std;
int main(){
    string a;cin>>a;
    int A=a.size();
    int n=0;
    for(char i='a';i<='z';++i){
        int k=0;
        for(int j=0;j<A;++j){
            if(a[j]==i)++k;
        }
        if(k%2==1)++n;
    }
    cout<<(n==0||n%2==1?"First":"Second")<<'\n';
    return 0;
}
