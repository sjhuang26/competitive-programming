/*
Codeforces
496D
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool a[100000];int kp[100000];
int main(){
    int A,la=0,lb=0;cin>>A;// t s
    vector<int>ap,bp;
    vector<pair<int,int>>r;
    for(int i=0;i<A;++i){
        int x;cin>>x;
        if(a[i]=x==2){
            bp.push_back(i);
            kp[i]=ap.size();
        }else{
            ap.push_back(i);
            kp[i]=bp.size();
        }
    }
    //for(int i=0;i<A;++i)cout<<kp[i]<<' ';cout<<endl;
    for(int i=1;i<=A;++i){
        //cout<<'n';
        int wa=0,wb=0,pa=0,pb=0;
        while(1){
            //cout<<pa<<' '<<pb<<endl;
            int wm=max(wa,wb);
            int u,v;
            if(pa+i>ap.size())u=1e9;
            else u=ap[pa+i-1];
            if(pb+i>bp.size())v=1e9;
            else v=bp[pb+i-1];
            if(u==1e9&&v==1e9)break;
            if(u>v)++wb,pb+=i,pa=kp[bp[pb-1]];else ++wa,pa+=i,pb=kp[ap[pa-1]];
            if(pa==ap.size()&&pb==bp.size()){
                if(max(wa,wb)!=wm){
                    r.push_back({max(wa,wb),i});
                }
                break;
            }
        }
    }
    sort(r.begin(),r.end());
    cout<<r.size()<<'\n';
    for(auto i:r){
        cout<<i.first<<' '<<i.second<<'\n';
    }
    return 0;
}
