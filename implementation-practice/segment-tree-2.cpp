#include<iostream>
using namespace std;
int t[100000]={},a[100000],N,NP;
void build(int x,int y,int k){
	if(x+1==y){
		t[k]=a[x];
	}else{
		int md=(x+y)/2;
		build(x,md,2*k);
		build(md,y,2*k+1);
		t[k]=t[k*2]+t[k*2+1];
	}
}
void build(){
	build(0,NP,1);
}
void update(int x,int y,int k,int u,int v){
	if(u<x||y<=u)return;
	if(x+1==y){
		t[k]=v;
		return;
	}
	int md=(x+y)/2;
	update(x,md,2*k,u,v);
	update(md,y,2*k+1,u,v);
	t[k]=t[2*k]+t[2*k+1];
}
void update(int u,int v){
	update(0,NP,1,u,v);
}
int query(int x,int y,int u,int v,int k){
	if(u<=x&&y<=v)return t[k];
	if(v<=x||y<=u)return 0;
	int md=(x+y)/2;
	return query(x,md,u,v,2*k)+query(md,y,u,v,2*k+1);
}
int query(int u,int v){
	query(0,NP,u,v,1);
}
void print_tree(){
	for(int i=0;i<NP*2;++i){
		cout<<t[i];
		if(i!=NP*2)cout<<' ';
	}cout<<'\n';
}
int main(){
	cin>>N;
	NP=1;
	while(N>NP)NP*=2;
	for(int i=0;i<N;++i)cin>>a[i];
	build();
	int upd;cin>>upd;
	for(int i=0;i<upd;++i){
		int u,v;cin>>u>>v;update(u,v);
		print_tree();
	}
	int qr;cin>>qr;
	for(int i=0;i<qr;++i){
		int u,v;cin>>u>>v;cout<<query(u,v)<<'\n';
	}
	return 0;
}
