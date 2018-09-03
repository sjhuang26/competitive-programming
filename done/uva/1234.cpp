/*
UVa
1234
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,p[10000],s[10000],r;
vector<pair<int,pair<int,int>>>q;
int getp(int u){
	return p[u]==u?u:p[u]=getp(p[u]);
}
bool uni(int a,int b){
	a=getp(a);b=getp(b);
	if(a==b)return 0;
	if(s[a]>s[b]){
		p[b]=a;
		s[a]+=s[b];
	}else{
		p[a]=b;
		s[b]+=s[a];
	}
	return 1;
}
int main(){
	int T;cin>>T;
	while(T--){
		cin>>N>>M;
		for(int i=0;i<N;++i)p[i]=i,s[i]=1;
		q.clear();
		r=0;
		for(int i=0;i<M;++i){
			int u,v,x;cin>>u>>v>>x;--u;--v;
			q.push_back({-x,{u,v}});
			r+=x;
		}
		sort(q.begin(),q.end());
		for(auto&i:q){
			int u=i.second.first,v=i.second.second,w=-i.first;
			if(uni(u,v))r-=w;
		}
		cout<<r<<'\n';
	}
	return 0;
}
