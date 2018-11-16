/*
UVa
11159
*/
#include<iostream>
#include<vector>
using namespace std;
int a[100],b[100],N,M;
vector<vector<int>>g;
vector<int>ma;
vector<bool>f;
int augment(int u){
	if(f[u])return 0;
	f[u]=1;
	for(int v:g[u]){
		if(ma[v]==-1||augment(ma[v])){
			ma[v]=u;
			return 1;
		}
	}
	return 0;
}
int main(){
	int T,CASES=0;cin>>T;
	while(T--){
		++CASES;
		cin>>N;
		for(int i=0;i<N;++i)cin>>a[i];
		cin>>M;
		for(int i=0;i<M;++i)cin>>b[i];
		g=vector<vector<int>>(N);
		ma=vector<int>(N+M,-1);
		f=vector<bool>();
		for(int i=0;i<N;++i)for(int j=0;j<M;++j){
			if(a[i]==0||b[j]==0){
				if(!(a[i]==0&&b[j]!=0)){
					g[i].push_back(j+N);
				}
			}else if(b[j]%a[i]==0){
				g[i].push_back(j+N);
			}
		}
		int r=0;
		for(int i=0;i<N;++i){
			f.assign(N,0);
			r+=augment(i);
		}
		cout<<"Case "<<CASES<<": "<<r<<'\n';
	}
	return 0;
}
