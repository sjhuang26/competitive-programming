/*
Codeforces
116D
*/
#include<iostream>
#include<string>
using namespace std;
string a[150];
int main(){
	int N,M,x=0,r=0,stp=0;cin>>N>>M;int mr[151],ml[151];
	for(int i=0;i<N;++i){
		cin>>a[i];
		mr[i]=-1;ml[i]=M;
		for(int j=M-1;j>=0;--j)if(a[i][j]=='W'){
			mr[i]=j;break;
		}
		for(int j=0;j<M;++j)if(a[i][j]=='W'){
			ml[i]=j;break;
		}
		if(mr[i]!=-1||ml[i]!=M)stp=i;
	}
	mr[N]=-1;ml[N]=M;
	for(int i=0;i<N;++i){
		int rw=max(mr[i],mr[i+1]);
		int lw=min(ml[i],ml[i+1]);
		//cout<<rw<<' '<<lw<<endl;
		if(i%2==0&&rw>x)r+=rw-x,x=rw;
		if(i%2==1&&lw<x)r+=x-lw,x=lw;
		if(stp==i)break;
		++r;
	}
	cout<<r<<'\n';
	return 0;
}
