/*
Codeforces
61D
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int>ii;
int main(){
	int V;cin>>V;
	ll S=0;
	vector<vector<ii>>g(V,vector<ii>());
	for(int i=0;i<V-1;++i){
		int a,b,w;cin>>a>>b>>w;
		--a;--b;
		//cout<<a<<' '<<b<<' '<<w<<endl;
		g[a].push_back({b,w});
		g[b].push_back({a,w});
		S+=w;
	}
	ll pm=-1;
	set<pair<ll,int>>q;//d v
	ll d[100000];
	bool v[100000]={};
	for(int i=0;i<V;++i)d[i]=1e18;
	d[0]=0;
	q.insert({d[0],0});
	while(!q.empty()){
		auto rw=q.begin();//cout<<'#'<<endl;
		ll cd=rw->first;
		int x=rw->second;
		q.erase(rw);
		if(v[x])continue;
		//cout<<cd<<' '<<x<<endl;
		if(cd>pm)pm=cd;
		v[x]=1;
		for(auto i:g[x])if(!v[i.first]&&cd+i.second<d[i.first]){
			q.erase({d[i.first],i.first});
			d[i.first]=cd+i.second;
			q.insert({d[i.first],i.first});
		}
	}
	cout<<2*S-pm<<'\n';
	return 0;
}
