/*
Codeforces
580C
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool at[100000],f[100000];
int ct[100000];
int main(){
	int V,B;cin>>V>>B;
	for(int i=0;i<V;++i){
		char x;cin>>x;
		at[i]=x=='1';
		f[i]=0;
		ct[i]=0;
	}
	vector<vector<int>>g(V,vector<int>());
	for(int i=0;i<V-1;++i){
		int a,b;cin>>a>>b;
		--a;--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	queue<int>q;
	q.push(0);
	f[0]=1;
	int r=0;
	while(!q.empty()){
		int a=q.front();q.pop();
		//cout<<a<<endl;
		ct[a]=(at[a]?ct[a]+1:0);
		if(ct[a]>B)continue;
		bool isp=false;
		for(int b:g[a])if(!f[b]){
			ct[b]=ct[a];
			f[b]=1;
			isp=true;
			q.push(b);
		}
		if(!isp)++r;//cout<<"A="<<a<<'\n';
	}
	cout<<r<<'\n';
	return 0;
}