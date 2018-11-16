/*
UVa
10480
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
	while(true){
		//cout<<"-------"<<endl;
		int V,E;cin>>V>>E;
		if(V==0)break;
		vector<vector<int>>ga(V);
		int c[50][50];
		for(int i=0;i<E;++i){
			int u,v,x;cin>>u>>v>>x;--u;--v;
			ga[u].push_back(v);
			ga[v].push_back(u);
			c[u][v]=x;
			c[v][u]=x;
		}
		bool w=1;
		while(w){
			w=0;
			queue<int>q;
			vector<int>p(V,-1);
			q.push(0);//S=0 T=1
			while(!q.empty()){
				int u=q.front();q.pop();
				if(u==1){
					w=1;
					break;
				}
				for(int v:ga[u]){
					if(p[v]==-1&&c[u][v]>0){
						p[v]=u;
						q.push(v);
					}
				}
			}
			if(w){
				int fl=1e9;
				for(int i=1;i!=0;i=p[i]){
					fl=min(fl,c[p[i]][i]);
				}
				for(int i=1;i!=0;i=p[i]){
					c[p[i]][i]-=fl;
					c[i][p[i]]+=fl;
				}
			}
		}
		queue<int>q;q.push(0);
		vector<bool>f(V);
		while(!q.empty()){
			int u=q.front();q.pop();
			if(f[u])continue;
			f[u]=1;
			for(int v:ga[u]){
				if(!f[v]&&c[u][v]>0)q.push(v);
			}
		}
		//for(int i=0;i<V;++i)cout<<f[i]<<' ';cout<<endl;
		for(int i=0;i<V;++i){
			for(int j:ga[i]){
				if(f[i]&&!f[j]){
					cout<<i+1<<' '<<j+1<<'\n';
				}
			}
		}
		cout<<'\n';
	}
	return 0;
}
