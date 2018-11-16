/*
Codeforces
4D
*/
#include<iostream>
#include<cstring>
using namespace std;
int N,S,T,a[5000],b[5000],d[5000],p[5000];
int search(int u){
	if(d[u]!=-1)return d[u];
	d[u]=1;
	for(int i=0;i<N;++i){
		if(a[u]<a[i]&&b[u]<b[i]){
			int x=search(i)+1;
			if(x>d[u])d[u]=x,p[u]=i;
		}
	}
	return d[u];
}
int main(){
	cin>>N>>S>>T;
	for(int i=0;i<N;++i)cin>>a[i]>>b[i];
	memset(d,-1,sizeof(d));
	memset(p,-1,sizeof(p));
	int r=-1;
	for(int i=0;i<N;++i){
		if(a[i]>S&&b[i]>T){
			int x=search(i);
			if(r==-1||x>d[r])r=i;
		}
	}
	if(r==-1){
		cout<<"0\n";
	}else{
		cout<<d[r]<<'\n';
		for(int i=0,u=r;i<d[r];++i,u=p[u]){
			cout<<(u+1);if(i!=d[r]-1)cout<<' ';
		}
		cout<<'\n';
	}
	return 0;
}