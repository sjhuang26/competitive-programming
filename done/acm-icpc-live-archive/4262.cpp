/*
ACM-ICPC Live Archive
4262
*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
vector<vector<int>>g,gi;
vector<bool>f;
stack<int>q;
void rec(int x){
	if(f[x])return;
	f[x]=1;
	for(int i:g[x])rec(i);
	q.push(x);
}
void rec2(int x){
	//cout<<'r'<<x<<endl;
	if(f[x])return;
	//cout<<'@'<<endl;
	f[x]=1;
	for(int i:gi[x])rec2(i);
}
int main(){
	int T;cin>>T;
	for(int te=0;te<T;++te){
		//cout<<"--"<<endl;
		int N,M,r=0,DIS;cin>>N>>M;
		g.clear();gi.clear();
		g.resize(N);gi.resize(N);
		f.clear();
		f.resize(N,0);
		while(!q.empty())q.pop();
		for(int i=0;i<M;++i){
			int u,v;cin>>u>>v;--u;--v;
			g[u].push_back(v);
			gi[v].push_back(u);
		}
		cin>>DIS;
		for(int i=0;i<N;++i)rec(i);
		fill(f.begin(),f.end(),0);
		while(!q.empty()){
			int x=q.top();q.pop();
			//cout<<'>'<<x<<endl;
			if(f[x])continue;
			rec2(x);
			//cout<<'B'<<endl;
			++r;
		}
		cout<<r<<'\n';
	}
	return 0;
}
