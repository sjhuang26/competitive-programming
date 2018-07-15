/*
Codeforces
732D
(can't debug)
*/
#include<iostream>
using namespace std;
int a[100000],m[100000];
bool sf[100000],u[100000];
int main(){
	int N,M;cin>>N>>M;
	for(int i=0;i<N;++i)cin>>a[i];
	for(int i=0;i<M;++i)cin>>m[i];
	int lo=0,hi=N,r=-1;
	while(lo<=hi){
		cout<<"!!\n";
		int md=(lo+hi)/2,sfc=0;
		bool wr=1;
		for(int i=0;i<M;++i)sf[i]=0;
		for(int i=md-1;i>=0;--i){
			int t=a[i];
			if(t!=0&&!sf[t-1])u[i]=1,sf[t-1]=1,++sfc;
			else u[i]=0;
		}
		if(sfc!=M)wr=0;
		int tp=-1,ap=0;
		if(wr)while(true){
			cout<<'b'<<md<<' '<<sfc<<' '<<tp<<' '<<ap<<'\n';
			++tp;
			while(tp<md&&!u[tp])++tp;
			if(tp>=md)break;
			int t=a[tp]-1;
			ap+=m[t];
			if(ap>tp){
				wr=0;
				break;
			}
			cout<<md<<' '<<sfc<<' '<<tp<<' '<<ap<<'\n';
		}
		if(wr){
			r=(r==-1?md:min(r,md));
			hi=md-1;
		}else{
			lo=md+1;
		}
	}
	cout<<r<<'\n';
	return 0;
}
