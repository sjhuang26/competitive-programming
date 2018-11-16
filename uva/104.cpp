/*
UVa
104
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
double a[20][20];
//DP [distance][node]=maxvalue with predecessor -> (distance-1, node)
double d[21][20];
int p[21][20],N;
int main(){
    while(1){
        if(!(cin>>N))break;
        for(int i=0;i<N;++i){
            int j=0;
            while(1){
                if(i==j)++j;
                if(j==N)break;
                cin>>a[i][j];
                ++j;
            }
        }
        int w=0;
        vector<pair<int,string>>res;
        for(int s=0;s<N;++s){
            for(int i=0;i<=N;++i)for(int j=0;j<N;++j)d[i][j]=0;
            d[0][s]=1;
            for(int i=1;i<=N;++i){
                for(int j=0;j<N;++j)d[i][j]=0;
                for(int j=0;j<N;++j){
                    for(int k=0;k<N;++k)if(j!=k){
                        double x=a[j][k]*d[i-1][j];
                        if(x>d[i][k]){
                            d[i][k]=x;
                            p[i][k]=j;
                        }
                    }
                }
                //cout<<d[i][s]<<'d'<<endl;
                if(d[i][s]>1.01){
                    w=i;
                    break;
                }
            }
            if(w!=0){
                int x=s;
                vector<int>r;
                for(int i=w;i>=1;--i){
                    r.push_back(x+1);
                    x=p[i][x];
                }
                r.push_back(s+1);
                string rr;
                for(int i=r.size()-1;i>=0;--i){
                    rr+=to_string(r[i]);if(i!=0)rr+=' ';
                }
                rr+='\n';
                //cout<<rr<<endl;
                res.push_back({w,rr});
            }
        }
        if(res.size()==0)cout<<"no arbitrage sequence exists\n";
        else{
            sort(res.begin(),res.end());
            cout<<res[0].second;
        }
    }
    return 0;
}
