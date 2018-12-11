/*
(accepted)
Author: Suhao Jeffrey Huang
Main ideas:
	* DP strategy
	* Start by finding all the columns/rows of dangos
	* overlapping regions of dango columns+rows are always in a diagonal pattern
	* Traverse each diagonals of the 2D grid, bottom-left to top-right
	* DP array:
		d[a (from 0 to 3)][b]: at the bth dango in the diagonal (0 = bottom-left-most point), and where the more recent previous point in the diagonal where a horizontal can be placed is b-a: how many dango rows+columns can be made?
	* whenever a dango column is placed, it blocks rows below it
*/
#include<iostream>
#include<string>
using namespace std;
// N, M <= 3000
int N,M,d[3][3000],a[3000][3000];
bool fv[3000][3000]={},fh[3000][3000]={};
int main(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		string in;cin>>ws>>in;
		for(int j=0;j<M;++j){
			if(in[j]=='R')a[i][j]=0;
			if(in[j]=='G')a[i][j]=1;
			if(in[j]=='W')a[i][j]=2;
		}
	}
	// vertical
	for(int i=0;i<N-2;++i){
		for(int j=0;j<M;++j){
			if(a[i][j]==0&&a[i+1][j]==1&&a[i+2][j]==2)fv[i][j]=1;
		}
	}
	// horizontal
	for(int i=0;i<N;++i){
		for(int j=0;j<M-2;++j){
			if(a[i][j]==0&&a[i][j+1]==1&&a[i][j+2]==2)fh[i][j]=1;
		}
	}
	int ans=0;
	for(int i=0;i<N;++i){
		int j=i,k=0,m=0;
		while(j!=-1&&k!=M){
			d[0][m]=d[1][m]=d[2][m]=0;
			if(m>0){
				if(fh[j][k])d[0][m]=d[0][m-1]+1;
				else if(fv[j][k])d[0][m]=d[2][m-1]+1;
				d[0][m]=max(d[0][m],d[0][m-1]);
			}else{
				d[0][m]=fh[j][k]||fv[j][k];
			}
			if(m>0){
				if(fv[j][k])d[1][m]=d[2][m-1]+1;
				d[1][m]=max(d[1][m],d[0][m-1]);
			}else{
				d[1][m]=fv[j][k];
			}
			if(m>0){
				if(fv[j][k])d[2][m]=d[2][m-1]+1;
				d[2][m]=max(d[2][m],d[1][m-1]);
			}else{
				d[2][m]=fv[j][k];
			}
			--j;++k;++m;
		}
		ans+=d[0][m-1];
	}
	// nearly duplicated code 
	for(int i=1;i<M;++i){
		int j=N-1,k=i,m=0;
		while(j!=-1&&k!=M){
			d[0][m]=d[1][m]=d[2][m]=0;
			if(m>0){
				if(fh[j][k])d[0][m]=d[0][m-1]+1;
				else if(fv[j][k])d[0][m]=d[2][m-1]+1;
				d[0][m]=max(d[0][m],d[0][m-1]);
			}else{
				d[0][m]=fh[j][k]||fv[j][k];
			}
			if(m>0){
				if(fv[j][k])d[1][m]=d[2][m-1]+1;
				d[1][m]=max(d[1][m],d[0][m-1]);
			}else{
				d[1][m]=fv[j][k];
			}
			if(m>0){
				if(fv[j][k])d[2][m]=d[2][m-1]+1;
				d[2][m]=max(d[2][m],d[1][m-1]);
			}else{
				d[2][m]=fv[j][k];
			}
			--j;++k;++m;
		}
		ans+=d[0][m-1];
	}
	cout<<ans<<'\n';
	return 0;
}