/*
Codeforces
168D
*/
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
int N,L,K;
double d[2][201][201];
int mx(int a){
	return (a>=N?1e9:a);
}
int rd(int a){
	return min(a,N);
}
int main(){
	cin>>N>>L>>K;
	vector<pair<int,double>>a(N);//capchange prob
	for(int i=0;i<N;++i){
		int x;
		cin>>x;
		a[i].second=(double)x/100;
	}
	for(int i=0;i<N;++i)cin>>a[i].first;
	sort(a.begin(),a.end(),greater<pair<int,double>>());
	//DP [cap][tourswon] t=tour#
	int dl=0,dn=1;
	for(int i=0;i<=N;++i)for(int j=0;j<=N;++j)d[dl][i][j]=0;
	d[dl][rd(K)][0]=1;
	for(int i=0;i<N;++i){
		for(int j=0;j<=N;++j)for(int k=0;k<=N;++k){
			d[dn][j][k]=0;
		}
		for(int j=0;j<=N;++j)for(int k=0;k<=N;++k){
			//win
			if(rd(mx(j)+a[i].first)>=0)d[dn][rd(mx(j)+a[i].first)][rd(mx(k)+1)]+=d[dl][j][k]*a[i].second;
			//lose
			d[dn][j][k]+=d[dl][j][k]*(1.0-a[i].second);
		}
		/*cout<<"+++++++\n";
		for(int j=0;j<=N;++j){
			for(int k=0;k<=N;++k)cout<<d[dn][j][k]<<' ';
			cout<<endl;
		}*/
		int aux=dl;dl=dn;dn=aux;
	}
	double r=0;
	for(int i=0;i<=N;++i){
		for(int j=L;j<=N;++j){
			r+=d[dl][i][j];
		}
	}
	cout<<fixed<<setprecision(12);
	cout<<r<<'\n';
}