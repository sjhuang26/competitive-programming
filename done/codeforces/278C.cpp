/*
Codeforces
278C
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int>ii;
int main(){
	int N,M,sv,cst=0;cin>>N>>M;
	bool a[100][100]={};
	bool isl[100],isal=true;
	for(int i=0;i<N;++i){
		int k;cin>>k;
		isl[i]=k==0;
		if(k>0)isal=false,sv=i;
		else ++cst;
		for(int j=0;j<k;++j){
			int x;cin>>x;
			a[i][x-1]=1;
		}
	}
	//cout<<"$"<<cst;
	if(isal){//edge
		cout<<N<<'\n';
		return 0;
	}
	int g[100][100];
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			g[i][j]=-99;//not used
			if(isl[i]||isl[j])continue;
			g[i][j]=1;
			for(int k=0;k<M;++k)if(a[i][k]&&a[j][k]){
				g[i][j]=0;break;
			}
		}
	}
	set<ii>q;
	int d[100],e[100];
	for(int i=0;i<N;++i)d[i]=1e9;
	d[sv]=0;
	e[sv]=-1;
	q.insert({d[sv],sv});
	while(!q.empty()){
		auto rw=q.begin();q.erase(rw);
		int x=rw->second;
		//cout<<e[x]<<' '<<rw->second<<' '<<rw->first<<'\n';
		if(e[x]!=-1)cst+=g[e[x]][x];
		for(int i=0;i<N;++i){
			if(i!=x&&!isl[i]&&d[i]>g[x][i]){
				q.erase({d[i],i});
				//cout<<"RELAX"<<x<<' '<<i<<'\n';
				d[i]=g[x][i];
				e[i]=x;
				q.insert({d[i],i});
			}
		}
	}
	cout<<cst<<'\n';
}
