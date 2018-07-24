/*
Codeforces
681D
(failed)
*/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int a[100100],g[100100],d[100100],p[100100];
vector<pair<int,int>>r;
int main(){
	int V,E;cin>>V>>E;
	for(int i=0;i<V;++i)g[i]=-1,d[i]=-1,p[i]=-1;
	for(int i=0;i<E;++i){
		int x,y;cin>>x>>y;
		--x;--y;
		g[y]=x;
	}
	for(int i=0;i<V;++i){
		int x;cin>>x;--x;
		p[x]=x;
		a[i]=x;
	}
	bool w=1;
	for(int i=0;i<V;++i){
		int pt=i;
		while(p[pt]==-1)pt=g[pt];
		int x=p[pt];
		if(x!=a[i]){
			w=0;
			break;
		}
		pt=i;
		while(p[pt]==-1)p[pt]=x,pt=g[pt];
	}
	if(w){
		for(int i=0;i<V;++i){
			int ct=0,pt=i;
			while(g[pt]!=-1&&d[pt]==-1)pt=g[pt],++ct;
			if(g[pt]==-1)d[pt]=0;
			//cout<<"NEW"<<endl;
			for(int j=ct+d[pt],pt=i;j>=ct;--j){
				//cout<<j<<endl;
				d[pt]=j;
				pt=g[pt];
			}
			if(p[i]==i)r.push_back({-d[i],i});
		}
		sort(r.begin(),r.end());
		cout<<r.size()<<'\n';
		for(auto i:r){
			cout<<i.second+1<<'\n';
		}
	}else{
		cout<<-1<<'\n';
	}
	return 0;
}
