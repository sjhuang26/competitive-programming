/*
Codeforces
66A
*/
#include<iostream>
#include<string>
using namespace std;
int comp(string a,string b){
    if(a[0]=='-'&&b[0]!='-')return -1;
    if(b[0]=='-'&&a[0]!='-')return 1;
    int rev=a[0]=='-'&&b[0]=='-'?-1:1;
    if(a[0]=='-')a=a.substr(1);
    if(b[0]=='-')b=b.substr(1);
    if(a.length()>b.length())return rev;
    if(a.length()<b.length())return -rev;
    for(int i=0;i<a.length();++i){
        if(a[i]>b[i])return rev;
        if(b[i]>a[i])return -rev;
    }
    return 0;
}
bool rg(string a,string b,string x){
    return comp(a,x)!=1&&comp(x,b)!=1;
}
int main(){
    string a;cin>>a;
    if(rg("-128","127",a)){
        cout<<"byte\n";
        return 0;
    }
    if(rg("-32768","32767",a)){
        cout<<"short\n";
        return 0;
    }
    if(rg("-2147483648","2147483647",a)){
        cout<<"int\n";
        return 0;
    }
    if(rg("-9223372036854775808","9223372036854775807",a)){
        cout<<"long\n";
        return 0;
    }
    cout<<"BigInteger\n";
    return 0;
}
