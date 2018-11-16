/*
Codeforces
400D
*/
#include<iostream>
using namespace std;
struct o{
	int a,b,w;
};
int p[100000],h[100000],tp[100000],k[500],fw[500][500],N,M,K;
int getp(int n){
	return p[n]==n?n:p[n]=getp(p[n]);
}
bool un(int a,int b){
	a=getp(a);
	b=getp(b);
	if(a==b)return false;
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
int main(){
	cin>>N>>M>>K;
	int tpp=0;
	for(int i=0;i<K;++i){
		int a;cin>>a;k[i]=a;
		for(int j=0;j<a;++j)tp[tpp]=i,++tpp;
	}
	for(int i=0;i<K;++i)for(int j=0;j<K;++j)fw[i][j]=i==j?0:1e9;
	for(int i=0;i<N;++i)p[i]=i,h[i]=1;
	for(int i=0;i<M;++i){
		o x;cin>>x.a>>x.b>>x.w;
		--x.a;--x.b;
		if(x.w==0)un(x.a,x.b);
		fw[tp[x.a]][tp[x.b]]=min(fw[tp[x.a]][tp[x.b]],x.w),fw[tp[x.b]][tp[x.a]]=min(fw[tp[x.b]][tp[x.a]],x.w);
	}
		//for(int i=0;i<N;++i)cout<<h[i]<<' ';cout<<endl;
	tpp=0;
	for(int i=0;i<K;++i){
		for(int j=0;j<k[i];++j){
			if(getp(tpp)!=getp(tpp+j)){
				cout<<"No\n";
				return 0;
			}
		}
		tpp+=k[i];
	}
	for(int k=0;k<K;++k)
	for(int i=0;i<K;++i)
	for(int j=0;j<K;++j)
	if(fw[i][j]>fw[i][k]+fw[k][j])fw[i][j]=fw[i][k]+fw[k][j];
	cout<<"Yes\n";
	for(int i=0;i<K;++i){
		for(int j=0;j<K;++j){
			cout<<(fw[i][j]==1e9?-1:fw[i][j]);
			if(j!=K-1)cout<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
