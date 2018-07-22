/*
Codeforces
230D
*/
#include<iostream>
#include<set>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int>ii;
ll d[200000];
int main(){
	int V,E;cin>>V>>E;
	vector<set<ll>>c(V);
	vector<vector<ii>>g(V);
	for(int i=0;i<E;++i){
		int x,y,w;cin>>x>>y>>w;--x;--y;
		g[x].push_back({y,w});
		g[y].push_back({x,w});
	}
	for(int i=0;i<V;++i){
		int K;cin>>K;
		for(int j=0;j<K;++j){
			int x;cin>>x;c[i].insert(x);
		}
		d[i]=1e18;
	}
	set<ii>q;
	d[0]=0;
	q.insert({d[0],0});
	while(!q.empty()){
		auto rw=q.begin();
		int u=rw->second;
		//cout<<'q'<<u<<endl;
		q.erase(rw);
		ll t=d[u];
		while(c[u].count(t))++t;
		for(ii i:g[u]){
			int v=i.first,w=i.second;
			if(t+w<d[v]){
				q.erase({d[v],v});
				d[v]=t+w;
				q.insert({d[v],v});
			}
		}
	}
	cout<<(d[V-1]==1e18?-1:d[V-1])<<'\n';
	return 0;
}
