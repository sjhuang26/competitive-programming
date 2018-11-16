/*
Codeforces
246D
*/
#include<iostream>
#include<set>
using namespace std;
int N,M,a[100000];
set<int>s[100000];
int main(){
	cin>>N>>M;
	for(int i=0;i<N;++i)cin>>a[i],--a[i],s[a[i]].insert(a[i]);
	for(int i=0;i<M;++i){
		int u,v;cin>>u>>v;u=a[u-1];v=a[v-1];
		s[u].insert(v),s[v].insert(u);
	}
	int r=-1,rn=-1;
	for(int i=100000-1;i>=0;--i){
		int x=s[i].size();
		if(x>=rn)r=i+1,rn=x;//,cout<<x;
	}
	cout<<r<<'\n';
	return 0;
}
