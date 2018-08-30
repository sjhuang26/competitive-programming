/*
UVa
10092
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int MX=1022;
int c[MX][MX],pr[MX];//1+20+1000+1
vector<vector<int>>g;
void ade(int a,int b,int w){
	g[a].push_back(b);
	g[b].push_back(a);
	c[a][b]=w;
}
int main(){
	while(1){
		int A,B;cin>>A>>B;
		if(A==B&&B==0)break;
		int S=0,T=1+A+B,V=1+A+B+1;
		memset(c,0,sizeof(c));
		g=vector<vector<int>>(V);
		int desf=0;
		for(int i=0;i<A;++i){
			int x;cin>>x;
			desf+=x;
			ade(S,i+1,x);
		}
		for(int i=0;i<B;++i){
			int x,y;cin>>x;
			for(int j=0;j<x;++j){
				cin>>y;--y;
				ade(y+1,i+1+A,1);
			}
		}
		for(int i=0;i<B;++i)ade(1+A+i,T,1);
		//max flow
		bool w=1;
		int rf=0;
		while(w){
			w=0;
			queue<int>q;
			q.push(S);
			memset(pr,-1,sizeof(pr));
			while(!q.empty()){
				int u=q.front();
				q.pop();
				if(u==T){
					w=1;
					break;
				}
				for(int v:g[u]){
					if(pr[v]==-1&&c[u][v]>0){
						pr[v]=u;
						q.push(v);
					}
				}
			}
			if(w){
				int fl=1e9;
				for(int i=T;i!=S;i=pr[i]){
					fl=min(fl,c[pr[i]][i]);
				}
				//cout<<fl<<endl;
				for(int i=T;i!=S;i=pr[i]){
					c[pr[i]][i]-=fl;
					c[i][pr[i]]+=fl;
				}
				rf+=fl;
			}
		}
		cout<<(desf==rf)<<'\n';
		if(desf==rf)for(int i=0;i<A;++i){
			vector<int>r;
			for(int j:g[i+1]){
				if(c[i+1][j]==0){
					r.push_back(j-1-A+1);
				}
			}
			for(int j=0;j<r.size();++j){
				cout<<r[j];
				if(j!=r.size()-1)cout<<' ';
			}
			cout<<'\n';
		}
	}
	return 0;
}