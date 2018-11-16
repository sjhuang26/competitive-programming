/*
Algorithm practice
DFS
Iteration 1
7/4/2018
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
	int V,E;cin>>V>>E;
	vector<vector<int>>g(V,vector<int>());
	for(int i=0;i<E;++i){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	queue<int>q;
	q.push(0);
	vector<bool>f(V);
	while(!q.empty()){
		int a=q.front();q.pop();
		f[a]=1;
		cout<<"DFS: "<<a<<'\n';
		for(int b:g[a])if(!f[b])q.push(b);
	}
}