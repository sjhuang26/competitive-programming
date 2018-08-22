/*
Algorithm practice
Kosaraju
Iteration 1
8/17/2018
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int V,E,id=0;//id=index of current SCC
vector<vector<int>>g;
vector<vector<int>>gi;//inverse graph
stack<int>s;
vector<bool>f;//visited flag
vector<int>r;//result (the SCC that each node is in)
void rec2(int x){
	if(r[x]!=-1)return;
	r[x]=id;
	for(int i:gi[x])rec2(i);
}
void rec(int x){
	if(f[x])return;
	f[x]=1;
	for(int i:g[x])rec(i);
	s.push(x);
}
int main(){
	cin>>V>>E;
	g.resize(V);
	gi.resize(V);
	f.resize(V);
	r.resize(V,-1);//-1 = didn't visit
	for(int i=0;i<E;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u].push_back(v);
		gi[v].push_back(u);
	}
	for(int i=0;i<V;++i)rec(i);
	while(!s.empty()){
		int i=s.top();s.pop();
		if(r[i]==-1){
			rec2(i);
			++id;
		}
	}
	for(int i=0;i<V;++i){
		cout<<r[i];
		if(i!=V-1)cout<<' ';
	}
	cout<<'\n';
	return 0;
}
