/*
Codeforces
743D
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int a[200000];
ll d[200000],db[200000],ds[200000];
bool dp[200000]={};
vector<vector<int>>g;
void dfs(int n){
	//cout<<'d'<<n<<endl;
	d[n]=-1;
	ds[n]=a[n];
	ll ma=-1e17,mb=-1e17,mc=-1e17;
	for(int i:g[n])if(d[i]==-2){
		dfs(i);
		ds[n]+=ds[i];
		if(dp[i])mc=max(mc,db[i]),dp[n]=1;
		if(d[i]>ma){
			mb=ma;ma=d[i];
		}else if(d[i]>mb)mb=d[i];
	}
	//cout<<ma<<' '<<mb<<' '<<mc<<endl;
	d[n]=max(ds[n],ma);
	if(ma!=-1e17&&mb!=-1e17)dp[n]=1;
	db[n]=max(ma+mb,mc);
}
int main(){
	int V;cin>>V;
	for(int i=0;i<V;++i)cin>>a[i],d[i]=-2;
	g=vector<vector<int>>(V,vector<int>());
	for(int i=0;i<V-1;++i){
		int x,y;cin>>x>>y;--x;--y;
		//cout<<'i'<<x<<' '<<y<<endl;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0);
	if(dp[0])cout<<db[0]<<'\n';
	else cout<<"Impossible\n";
}
