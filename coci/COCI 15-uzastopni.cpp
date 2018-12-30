#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
typedef pair<int,int>ii;
int N,a[10000];
const int M=100;
vector<int>t[10000];
bitset<100>f[101];//100+1
vector<ii>d[10000];
vector<int>g[100];
void dfs(int u){
	for(int v:t[u])dfs(v);
	for(int i=0;i<M;++i)g[i].clear();
	for(int i=0;i<M+1;++i)f[i].reset();
	for(int v:t[u]){
		for(ii x:d[v])g[x.first].push_back(x.second);
	}
	for(int i=M-1;i>=0;--i){
		if(i==a[u]){
			f[i]|=f[i+1];
			f[i].set(i);
		}else for(int j:g[i]){
			if(a[u]<i||j<a[u]){
				f[i]|=f[j+1];
				f[i].set(j);
			}
		}
		for(int j=M-1;j>=0;--j){
			if(f[i][j]&&i<=a[u]&&a[u]<=j)d[u].emplace_back(i,j);
		}
	}
}
int main(){
	cin>>N;
	for(int i=0;i<N;++i)cin>>a[i],--a[i],f[i]=0;
	for(int i=0;i<N-1;++i){
		int u,v;cin>>u>>v;--u;--v;
		t[u].push_back(v);
	}
	dfs(0);
	cout<<d[0].size()<<'\n';
	return 0;
}