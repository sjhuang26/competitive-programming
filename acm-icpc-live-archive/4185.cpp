/*
ACM ICPC Live Archive
4185
*/
#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
int V,E,id;
vector<vector<int>>g,gi;
stack<int>s;
vector<bool>f;
vector<int>r;
void pin(int a,int b){
	//cout<<a<<' '<<b<<endl;
	g[a].push_back(b);
	gi[b].push_back(a);
}
void rec(int x){
	if(f[x])return;
	f[x]=1;
	for(int i:g[x])rec(i);
	s.push(x);
}
void rec2(int x){
	if(r[x]!=-1)return;
	r[x]=id;
	for(int i:gi[x])rec2(i);
}
int main(){
	while(1){
		if(!(cin>>V))break;
		V*=2;
		cin>>E;
		id=0;
		g.clear();gi.clear();f.clear();r.clear();
		g.resize(V);
		gi.resize(V);
		f.resize(V);
		r.resize(V,-1);
		for(int i=0;i<E;++i){
			string x,y;cin>>x>>y;
			bool j=x[0]=='+',k=y[0]=='+';
			int u=stoi(x.substr(1,x.size()))-1;
			int v=stoi(y.substr(1,y.size()))-1;
			//cout<<u<<'P'<<v<<' '<<j<<' '<<k<<endl;
			int vx=V/2;
			pin(u+vx*!!j,v+vx*!k);
			pin(v+vx*!!k,u+vx*!j);
		}
		for(int i=0;i<V;++i)rec(i);
		while(!s.empty()){
			int x=s.top();s.pop();
			rec2(x);
			++id;
		}
		bool w=1;
		for(int i=0;i<V/2;++i)if(r[i]==r[i+V/2]){
			w=0;break;
		}
		cout<<w<<'\n';
	}
}
