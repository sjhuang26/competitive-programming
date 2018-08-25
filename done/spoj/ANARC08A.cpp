/*
SPOJ
ANARC08A
(failed)
*/
#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct o{
	o*d[9];
	o(){
		for(int i=0;i<9;++i)d[i]=NULL;
	}
};
o g;
void gadd(string&u){
	o*x=&g;
	for(char i:u){
		int v=i-'1';
		if(x->d[v]==NULL)x->d[v]=new o;
		else x=x->d[v];
	}
}
bool gcheck(string&u){
	o*x=&g;
	for(char i:u){
		int v=i-'1';
		if(x->d[v]==NULL)return 0;
		else x=x->d[v];
	}
	return 1;
}
const int MOV[4][4]={{1,2,5,4},{2,3,6,5},{4,5,8,7},{5,6,9,8}};
int main(){
	int T=0;
	//int iters=0;
	while(1){
		++T;
		string ar;cin>>ar;
		if(ar=="0000000000")break;
		string a=ar.substr(1);
		int D=ar[0]-'0';
		queue<pair<int,string>>q;
		q.push({0,a});
		int w=-1;
		while(!q.empty()){
			//++iters;if(iters%1000==0)cout<<iters<<endl;
			auto x=q.front();
			int d=x.first;string u=x.second;
			//cout<<d<<' '<<u<<endl;
			q.pop();
			if(d>D||gcheck(u))continue;
			if(u=="123456789"){
				w=d;
				break;
			}
			gadd(u);
			for(int i=0;i<4;++i){
				string y=u;
				for(int j=0;j<4;++j){
					y[MOV[i][j]-1]=u[MOV[i][(j+5)%4]-1];
				}
				q.push({d+1,y});
			}
			for(int i=0;i<4;++i){
				string y=u;
				for(int j=0;j<4;++j){
					y[MOV[i][j]-1]=u[MOV[i][(j+3)%4]-1];
				}
				q.push({d+1,y});
			}
		}
		cout<<T<<". "<<w<<'\n';
	}
	return 0;
}