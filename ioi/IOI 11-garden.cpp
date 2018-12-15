#include "garden.h"
#include "gardenlib.h"

int traverse(int u,int p[],int d[],int P){
	if(d[u]!=-2)return d[u];
	if(u==P)return d[u]=0;
	if(p[u]==-1)return d[u]=-1;
	d[u]=-1;
	int x=traverse(p[u],p,d,P);
	if(x==-1){
		return d[u]=-1;
	}else{
		return d[u]=1+x;
	}
}
void count_routes(int N, int M, int P, int R[][2], int Q, int G[]){
	int ta[150000],tb[150000];
	for(int i=0;i<N;++i)ta[i]=tb[i]=-1;
	for(int i=0;i<M;++i){
		int u=R[i][0],v=R[i][1];
		if(ta[u]==-1)ta[u]=v;
		else if(tb[u]==-1)tb[u]=v;
		if(ta[v]==-1)ta[v]=u;
		else if(tb[v]==-1)tb[v]=u;
	}
	int p[300000];
	for(int i=0;i<N;++i){
		if(ta[i]==-1)p[i]=-1;
		else if(ta[ta[i]]==i)p[i]=ta[i]+N;
		else p[i]=ta[i];
		p[i+N]=(tb[i]==-1?ta[i]:tb[i]);
	}
	int d[300000];
	for(int i=0;i<2*N;++i)d[i]=-2;
	for(int i=0;i<2*N;++i){
		traverse(i,p,d,P);
	}
  	bool f[300000]={};
	int cyc=0;
	for(int i=P;i!=-1&&!f[i];i=p[i]){
		++cyc;f[i]=1;
		if(i==-1)cyc=1e9;
	}
	int dr[300000]={};
  	// NOTE: we can only start at primary nodes
	for(int i=0;i<N;++i)if(d[i]>=0)++dr[d[i]%cyc];
	for(int i=0;i<Q;++i){
		answer(dr[G[i]%cyc]);
	}
}