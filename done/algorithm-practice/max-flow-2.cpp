/*
Algorithm practice
Max flow
Iteration 2
8/16/2018
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
	int V,E,S,T;cin>>V>>E>>S>>T;--S;--T;
	vector<vector<int>>g(V,vector<int>());
	vector<vector<int>>gr(V,vector<int>());
	vector<vector<int>>c(V,vector<int>(V,0)),f(V,vector<int>(V,0));
	for(int i=0;i<E;++i){
		int u,v,x;cin>>u>>v>>x;--u;--v;
		g[u].push_back(v);
		g[v].push_back(u);
		gr[u].push_back(v);
		c[u][v]=x;
		f[v][u]=c[v][u]=x;
	}
	bool w=1;int r=0;
	while(w){
		queue<int>q;
		q.push(S);
		vector<int>pr(V,-1);
		w=0;
		while(!q.empty()&&!w){
			int u=q.front();q.pop();
			for(int v:g[u])if(pr[v]==-1&&c[u][v]-f[u][v]>0){
				pr[v]=u;
				if(v==T){
					w=1;
					int fl=1e9;
					for(int i=T;i!=S;i=pr[i])fl=min(fl,c[pr[i]][i]-f[pr[i]][i]);
					for(int i=T;i!=S;i=pr[i]){
						f[pr[i]][i]+=fl;
						f[i][pr[i]]-=fl;
					}
					r+=fl;
					break;
				}else{
					q.push(v);
				}
			}
		}
	}
	cout<<r<<'\n';
	for(int i=0;i<V;++i)for(int j:gr[i]){
		cout<<i+1<<" --> "<<j+1<<": flow="<<f[i][j]<<'\n';
	}
    return 0;
}
