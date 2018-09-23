/*
Codeforces
197D
*/
#include<iostream>
#include<string>
using namespace std;
int x[1500][1500],y[1500][1500],N,M,S,T;
string a[1500];
inline int md(int a,int b){
	return (b+(a%b))%b;
}
bool dfs(int i,int j){
	//cout<<i<<' '<<j<<endl;
	if(x[md(i,N)][md(j,M)]!=1e9){
		return (x[md(i,N)][md(j,M)]!=i||y[md(i,N)][md(j,M)]!=j);
	}
	x[md(i,N)][md(j,M)]=i;
	y[md(i,N)][md(j,M)]=j;
	if(a[md(i-1,N)][md(j,M)]!='#'&&dfs(i-1,j))return 1;
	if(a[md(i+1,N)][md(j,M)]!='#'&&dfs(i+1,j))return 1;
	if(a[md(i,N)][md(j-1,M)]!='#'&&dfs(i,j-1))return 1;
	if(a[md(i,N)][md(j+1,M)]!='#'&&dfs(i,j+1))return 1;
	return 0;
}
int main(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>a[i];
		for(int j=0;j<M;++j){
			if(a[i][j]=='S')S=i,T=j;
			x[i][j]=1e9;
		}
	}
	cout<<(dfs(S,T)?"Yes":"No")<<'\n';
	return 0;
}
