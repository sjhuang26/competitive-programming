/*
UVa
10276
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int T;cin>>T;
    for(int t=0;t<T;++t){
        int N;cin>>N;//50
        int s[50];
        for(int i=0;i<N;++i)s[i]=-1;
        for(int i=1;;++i){
            bool fail=true;
            for(int j=0;j<N;++j){
                bool works=false;
                if(s[j]==-1)works=true;
                else{
                    int x=round(sqrt(s[j]+i));
                    if(s[j]+i==x*x){
                        works=true;
                    }
                }
                if(works){
                    s[j]=i;
                    fail=false;
                    break;
                }
            }
            if(fail){
                cout<<i-1<<'\n';
                break;
            }
        }
    }
    return 0;
}
