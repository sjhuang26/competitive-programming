/*
Codeforces
189D
*/
#include<iostream>
using namespace std;
int a[60][60][60],d[60][60][60],N,M,T;
int main(){
	//n cities m cars
	cin>>N>>M>>T;

	for(int i=0;i<N;++i)for(int j=0;j<N;++j)for(int k=0;k<N;++k)d[i][j][k]=1e9;

	for(int k=0;k<M;++k)
	for(int i=0;i<N;++i)
	for(int j=0;j<N;++j)cin>>a[k][i][j];

	for(int m=0;m<M;++m){
		for(int k=0;k<N;++k)for(int i=0;i<N;++i)for(int j=0;j<N;++j){
			int x=a[m][i][k]+a[m][k][j];
			//cout<<a[m][i][j]<<endl;
			if(x<a[m][i][j])a[m][i][j]=x;
		}
	}

	//for(int i=0;i<N;++i)for(int j=0;j<N;++j)cout<<d[0][i][j]<<endl;

	for(int k=0;k<M;++k)for(int i=0;i<N;++i)for(int j=0;j<N;++j)
	d[0][i][j]=min(d[0][i][j],a[k][i][j]);

	for(int k=1;k<N;++k){
		for(int i=0;i<N;++i)for(int j=0;j<N;++j)d[k][i][j]=d[k-1][i][j];
		for(int i=0;i<N;++i)for(int j=0;j<N;++j)for(int m=0;m<N;++m){
			int x=d[k-1][i][m]+d[0][m][j];
			if(x<d[k][i][j])d[k][i][j]=x;
		}
	}

	for(int t=0;t<T;++t){
		int u,v,K;cin>>u>>v>>K;
		cout<<d[min(K,N-1)][u-1][v-1]<<'\n';
	}
	return 0;
}
