/*
Algorithm practice
Kruskal
Iteration 1
7/16/2018
*/
#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
typedef pair<int,int>ii;
vector<int>p,h;
struct o{
	int a,b,w;
};
int getp(int n){
	return p[n]==n?n:p[n]=getp(p[n]);
}
bool un(int a,int b){
	int pa=getp(a),pb=getp(b);
	if(pa!=pb){
		if(h[a]>h[b]){
			p[b]=a;
		}else if(h[b]>h[a]){
			p[a]=b;
		}else{
			p[b]=a;
			++h[a];
		}
		return true;
	}
	return false;
}
int main(){
	int V,E;cin>>V>>E;
	vector<vector<ii>>g(V);
	vector<o>e;
	for(int i=0;i<E;++i){
		int a,b,w;cin>>a>>b>>w;
		g[a].push_back({b,w});
		g[b].push_back({a,w});
		o x;x.a=a;x.b=b;x.w=w;e.push_back(x);
	}
	sort(e.begin(),e.end(),[](const o&a,o&b){
		return a.w<b.w;
	});
	p=vector<int>(V);
	for(int i=0;i<V;++i)p[i]=i;
	h=vector<int>(V,1);
	for(o i:e){
		if(un(i.a,i.b)){
			cout<<i.a<<' '<<i.b<<'\n';
		}
	}
	return 0;
}
