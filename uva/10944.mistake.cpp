/*
UVa
10944
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<tuple>
#include<string>
using namespace std;
bool f[20][20][32768];
string a[20];
int id[20][20],idc,N,M,S,T;
void dfs(int r,int c,int s,int d){
	cout<<r<<' '<<c<<' '<<s<<' '<<d<<endl;
	if(f[r][c][s])return;
	f[r][c][s]=1;
	if(a[r][c]=='#')s|=(1<<id[r][c]);
	if(s==(1<<idc)-1&&r==S&&c==T){
		cout<<d<<endl;
	}
	if(r>0)dfs(r-1,c,s,d+1);
	if(r<N-1)dfs(r+1,c,s,d+1);
	if(c>0)dfs(r,c-1,s,d+1);
	if(c<M-1)dfs(r,c+1,s,d+1);
}
int main(){
	while(1){
		if(!(cin>>N))break;
		cin>>M;
		for(int i=0;i<N;++i)cin>>ws,cin>>a[i];
		memset(f,0,sizeof(f));
		idc=0;
		for(int i=0;i<N;++i)for(int j=0;j<M;++j){
			if(a[i][j]=='L')S=i,T=j;
			if(a[i][j]=='#')id[i][j]=idc,++idc;
		}
		dfs(S,T,0,0);
	}
	return 0;
}
