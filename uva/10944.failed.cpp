/*
UVa
10944
*/
#include<iostream>
#include<string>
#include<tuple>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int N,M,si,cid,ix[16],iy[16],g[16][16],ITERS=0;
string a[20];
int d[1<<16][16];
int itd(int s,int u){
	//++ITERS;if(ITERS%1000000==0)cout<<ITERS<<endl;
	if(d[s][u]!=-1)return d[s][u];
	if(s==0)return d[s][u]=g[u][si];
	int r=1e9;
	for(int i=0;i<cid;++i){
		if((s&(1<<i))!=0){
			r=min(r,itd(s&~(1<<i),i)+g[u][i]);
		}
	}
	//cout<<s<<' '<<u<<' '<<r<<'\n';
	return d[s][u]=r;
}
int main(){
	while(1){
		if(!(cin>>N))break;
		cin>>M;
		for(int i=0;i<(1<<16);++i)for(int j=0;j<16;++j)d[i][j]=-1;
		cid=0;
		for(int i=0;i<N;++i){
			string x;cin>>x;a[i]=x;
			for(int j=0;j<M;++j){
				if(a[i][j]!='.'){
					if(a[i][j]=='L')si=cid;
					ix[cid]=i,iy[cid]=j,++cid;
				}
			}
		}
		for(int i=0;i<cid;++i)
			for(int j=0;j<cid;++j)
				g[i][j]=abs(ix[i]-ix[j])+abs(iy[i]-iy[j]);
		cout<<itd((((1<<cid)-1)&~(1<<si)),si)<<"\n";
	}
	return 0;
}