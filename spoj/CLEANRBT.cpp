/*
SPOJ
CLEANRBT
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef pair<int,int>ii;
int main(){
	while(1){
		//cout<<"NEWCASE"<<endl;
		int R,C;cin>>C>>R;
		//cout<<"RC"<<R<<C<<endl;
		if(R==0&&C==0)break;
		string a[20];
		vector<ii>t;//also includes robot start
		int si;
		for(int i=0;i<R;++i){
			cin>>a[i];
			for(int j=0;j<C;++j){
				char x=a[i][j];
				if(x=='o'){
					si=t.size();
					t.push_back({i,j});
				}else if(x=='*'){
					t.push_back({i,j});
				}
			}
		}
		int T=t.size();
		int d[20][20];
		int g[11][11];
		//cout<<"1"<<endl;
		//cout<<si<<' '<<t[0].first<<' '<<t[1].first<<endl;
		for(int i=0;i<T;++i){
			//bfs
			for(int i=0;i<R;++i)for(int j=0;j<C;++j)d[i][j]=1e9;
			queue<ii>q;
			q.push(t[i]);
			int D=0;
			while(!q.empty()){
				int Q=q.size();
				for(int m=0;m<Q;++m){
					auto rw=q.front();q.pop();
					int r=rw.first,c=rw.second;
					if(0>r||r>=R||0>c||c>=C||d[r][c]!=1e9||a[r][c]=='x')continue;
					d[r][c]=D;
					q.push({r-1,c});
					q.push({r+1,c});
					q.push({r,c-1});
					q.push({r,c+1});
				}
				++D;
			}
			for(int j=0;j<T;++j){
				g[i][j]=d[t[j].first][t[j].second];
			}
		}
		/*for(int i=0;i<T;++i){
			for(int j=0;j<T;++j)cout<<g[i][j];
			cout<<'\n';
		}*/
		int dp[2048][11];//s endv
		int DP=(1<<T);
		for(int i=0;i<DP;++i)for(int j=0;j<T;++j)dp[i][j]=1e9;
		for(int i=0;i<T;++i){
			dp[1<<i][i]=0;
		}
		for(int i=1;i<DP;++i){
			for(int j=0;j<T;++j){
				if((i&(1<<j))==0)continue;
				int r=dp[i][j];
				for(int k=0;k<T;++k)if((i&(1<<k))!=0&&g[k][j]!=1e9){
					r=min(r,dp[i&~(1<<j)][k]+g[k][j]);
				}
				//cout<<"DP"<<i<<' '<<j<<' '<<r<<'\n';
				dp[i][j]=r;
			}
		}
		int r=dp[(1<<T)-1][si];
		cout<<(r==1e9?-1:r)<<'\n';
	}
}
