/*
Codeforces
1005A
(contest)
*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int A;cin>>A;
    vector<int>r;
    int pv=-1;
    for(int i=0;i<A;++i){
        int x;cin>>x;
        if(x==1&&pv!=-1){
            r.push_back(pv);
        }
        pv=x;
    }
    r.push_back(pv);
    int R=r.size();
    cout<<R<<'\n';
    for(int i=0;i<R;++i){
        cout<<r[i];
        if(i!=R-1){
            cout<<' ';
        }
    }
    cout<<'\n';
    return 0;
}
