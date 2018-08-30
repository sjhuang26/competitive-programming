/*
ACM ICPC Live Archive
4326
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int g[15][15],a[15],N,M,p[15],s[15],ru[15];
vector<int>curs;
double r;
int getp(int u){
	return p[u]==u?u:(p[u]=getp(p[u]));
}
bool uni(int u,int v){
	u=getp(u);v=getp(v);
	if(u==v)return 0;
	if(s[u]>s[v]){
		p[v]=u;
		s[u]+=s[v];
	}else{
		p[u]=v;
		s[v]+=s[u];
	}
	return 1;
}
bool isin(int b,int m){
	return (m&(1<<b))!=0;
}
int main(){
	while(1){
		cin>>N>>M;
		if(N==0&&M==0)break;
		for(int i=0;i<N;++i)cin>>a[i];
		vector<pair<int,pair<int,int>>>e;
		r=1e9;
		for(int i=0;i<N;++i)for(int j=0;j<N;++j){
			cin>>g[i][j];
			e.push_back({g[i][j],{i,j}});
		}
		sort(e.begin(),e.end());
		for(int i=0;i<(1<<N);++i){
			int nodw=0;
			curs.clear();
			for(int j=0;j<N;++j)if((i&(1<<j))!=0)nodw+=a[j],curs.push_back(j);
			if(curs.size()==M){
				for(int j=0;j<N;++j)p[j]=j,s[j]=1;
				int rc=0,rw=0;
				for(auto j:e){
					//cout<<j.second.first<<j.second.second<<endl;
					if(!(isin(j.second.first,i)&&isin(j.second.second,i)))continue;
					if(uni(j.second.first,j.second.second))rw+=j.first,++rc;
					if(rc==M-1)break;
				}
				//cout<<"?"<<rc<<M-1<<endl;
				if(rc==M-1){
					double res=(double)rw/nodw;
					bool w=res<r;
					if(res==r){
						for(int i=0;i<M;++i){
							if(curs[i]<ru[i]){
								w=1;break;
							}
						}
					}
					if(w){
						for(int i=0;i<M;++i)ru[i]=curs[i];
						r=res;
					}
				}
			}
		}
		for(int i=0;i<M;++i){
			cout<<ru[i]+1;
			if(i!=M-1)cout<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
