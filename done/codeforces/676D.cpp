/*
Codeforces
676D
*/
#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<tuple>
using namespace std;
int a[1000][1000];
int d[1000][1000][4];
const string PARSE="*<vx>-xU^x|RxDL+";//TRBL
bool bi(int a,int b){
	b=(b+4)%4;
	//cout<<'b'<<((a&(1<<b))!=0)<<endl;
	return (a&(1<<b))!=0;
}
int main(){
	int N,M;cin>>N>>M;
	for(int i=0;i<N;++i){
		string x;cin>>x;
		for(int j=0;j<M;++j){
			a[i][j]=PARSE.find(x[j]);
			for(int k=0;k<4;++k){
				d[i][j][k]=-1;
			}
		}
	}
	int sr,sc,tr,tc;cin>>sr>>sc>>tr>>tc;--sr;--sc;--tr;--tc;
	queue<tuple<int,int,int,int>>q;//r c offset depth
	q.push({sr,sc,0,0});
	int rs=-1;
	while(!q.empty()){
		auto x=q.front();q.pop();
		int r=get<0>(x),c=get<1>(x),of=get<2>(x),dh=get<3>(x);
		if(0>r||r>=N||0>c||c>=M||d[r][c][of]!=-1)continue;
		//cout<<r<<'Q'<<c<<' '<<of<<' '<<dh<<endl;
		d[r][c][of]=dh;
		if(r==tr&&c==tc){
			//cout<<"@"<<endl;
			rs=dh;
			break;
		}
		++dh;
		q.push({r,c,(of+1)%4,dh});
		if(bi(a[r][c],3+of)&&bi(a[r-1][c],1+of))q.push({r-1,c,of,dh});//,cout<<'T';
		if(bi(a[r][c],2+of)&&bi(a[r][c+1],0+of))q.push({r,c+1,of,dh});//,cout<<'R';
		if(bi(a[r][c],1+of)&&bi(a[r+1][c],3+of))q.push({r+1,c,of,dh});//,cout<<'B';
		if(bi(a[r][c],0+of)&&bi(a[r][c-1],2+of))q.push({r,c-1,of,dh});//,cout<<'L';
	}
	cout<<rs<<'\n';
}
