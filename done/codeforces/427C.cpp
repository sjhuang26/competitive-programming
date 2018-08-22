/*
Codeforces
427C
*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
const int MD=1000000007;
stack<int>q;
vector<vector<int>>g,gi;
bool f[100000]={};
int a[100000],rm=2e9,rc=0;
void rec2(int x){
	if(f[x])return;
	f[x]=1;
	if(a[x]==rm)++rc;
	else if(a[x]<rm)rm=a[x],rc=1;
	for(int i:gi[x])rec2(i);
}
void rec(int x){
	if(f[x])return;
	f[x]=1;
	for(int i:g[x])rec(i);
	q.push(x);
}
int main(){
	int V;cin>>V;
	for(int i=0;i<V;++i)cin>>a[i];
	g=vector<vector<int>>(V);
	gi=vector<vector<int>>(V);
	int E;cin>>E;
	for(int i=0;i<E;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u].push_back(v);
		gi[v].push_back(u);
	}
	for(int i=0;i<V;++i)rec(i);
	for(int i=0;i<V;++i)f[i]=0;
	ll ra=0,rn=1;
	while(!q.empty()){
		int u=q.top();q.pop();
		rm=2e9;rc=0;
		rec2(u);
		if(rm!=2e9){
			ra+=rm;
			rn*=rc;rn%=MD;
		}
	}
	cout<<ra<<' '<<rn<<'\n';
	return 0;
}
