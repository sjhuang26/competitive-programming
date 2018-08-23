/*
UVa
10731
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
vector<vector<int>>g;
vector<int>id,lw;
vector<bool>fs,us;
vector<string>res;
stack<int>q;
int cid;
void scc(int i){
    //cout<<"SCC="<<i<<endl;
    id[i]=lw[i]=cid;
    ++cid;
    q.push(i);
    fs[i]=1;
    for(int j:g[i]){
        if(id[j]==-1){
            scc(j);
            lw[i]=min(lw[i],lw[j]);
        }else if(fs[j]){
            lw[i]=min(lw[i],id[j]);
        }
    }
    if(lw[i]==id[i]){
        vector<int>rs;
        while(1){
            int x=q.top();
            if(us[x])rs.push_back(x);
            q.pop();
            fs[x]=0;
            if(x==i)break;
        }
        sort(rs.begin(),rs.end());
        string re;
        for(int i=0;i<rs.size();++i){
            re+=(char)('A'+rs[i]);
            re+=(i!=rs.size()-1?' ':'\n');
        }
        res.push_back(re);
    }
}
int main(){
    bool ISF=1;
    while(1){
        int T;cin>>T;
        g=vector<vector<int>>(26);
        while(!q.empty())q.pop();
        id=vector<int>(26,-1);
        lw=vector<int>(26);
        fs=vector<bool>(26);
        us=vector<bool>(26);
        res=vector<string>();
        cid=0;
        if(T==0)break;
        if(!ISF)cout<<'\n';
        for(int i=0;i<T;++i){
            char x[5],y;
            for(int j=0;j<5;++j)cin>>x[j];
            cin>>y;
            for(int j=0;j<5;++j)if(x[j]!=y)g[y-'A'].push_back(x[j]-'A'),us[y-'A']=us[x[j]-'A']=1;
        }
        /*for(int i=0;i<26;++i){
            for(int j:g[i])cout<<j<<' ';
            cout<<endl;
        }*/
        for(int i=0;i<26;++i){
            if(id[i]==-1){
                scc(i);
            }
        }
        sort(res.begin(),res.end());
        for(string i:res){
            cout<<i;
        }
        ISF=0;
    }
    return 0;
}