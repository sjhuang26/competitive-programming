/*
Codeforces
418B
*/
#include<iostream>
typedef long long ll;
using namespace std;
ll d[1048576];
int main(){
	int N,M,B;cin>>N>>M>>B;
	int x[100],k[100],g[100]={};
	for(int i=0;i<N;++i){
		int u,v,w;cin>>u>>v>>w;
		x[i]=u;k[i]=v;
		for(int j=0;j<w;++j){
			int y;cin>>y;
			g[i]|=(1<<(y-1));
		}
		//cout<<g[i]<<endl;
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<N-1;++j){
			if(k[j]>k[j+1]){
				swap(x[j],x[j+1]);
				swap(k[j],k[j+1]);
				swap(g[j],g[j+1]);
			}
		}
	}
	ll rf=4e18;
	for(int j=0;j<(1<<M);++j)d[j]=4e18;
	d[0]=0;
	for(int i=0;i<N;++i){
		//cout<<"------"<<endl;
		//cout<<g[i]<<' '<<x[i]<<' '<<k[i]<<endl;
		for(int j=0;j<(1<<M);++j){
			d[j|g[i]]=min(d[j|g[i]],d[j]+x[i]);
		}
		rf=min(rf,d[(1<<M)-1]+(ll)k[i]*B);
		//for(int j=0;j<(1<<M);++j)cout<<d[j]<<' ';
		//cout<<endl;
	}
	cout<<(rf==4e18?-1:rf)<<'\n';
	return 0;
}
