/*
Baltic 11-Lamp (AC)
Key ideas:
* Only 1/2 of the points (the ones where x + y = even number) of the grid are reachable from the start point.
* So, use a BFS from the start point.
* The implementation of the deque is important, to make sure that the BFS doesn't visit vertices too early and that when a vertex is reachable from multiple paths, the lowest-cost path is taken (NOT the path that is traversed first).
*/
#include<iostream>
#include<string>
#include<queue>
using namespace std;
typedef pair<int,int>ii;
deque<pair<int,ii>>q;
bool a[500][500];
int f[501][501];
int N,M,dc=0,D=-1;
int main(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		string x;cin>>ws>>x;
		for(int j=0;j<M;++j){
			a[i][j]=(x[j]=='\\')!=((i+j)%2);
		}
	}
	for(int i=0;i<=N;++i)for(int j=0;j<=M;++j){
		if((i+j)%2==0)++dc;
		f[i][j]=1e9;
	}
	f[0][0]=0;
	q.push_back(make_pair(0,make_pair(0,0)));
	while(!q.empty()){
		auto&x=q.front();
		int h=x.first,u=x.second.first,v=x.second.second;
		q.pop_front();
		if(h!=f[u][v])continue;
		//cout<<h<<' '<<u<<' '<<v<<endl;
		if(u==N&&v==M){
			D=h;break;
		}
		if(u>0&&v>0&&f[u-1][v-1]>h+!a[u-1][v-1]){
			f[u-1][v-1]=h+!a[u-1][v-1];
			if(a[u-1][v-1])q.push_front(make_pair(h+!a[u-1][v-1],make_pair(u-1,v-1)));
			else q.push_back(make_pair(h+!a[u-1][v-1],make_pair(u-1,v-1)));
		}
		if(u>0&&v<M&&f[u-1][v+1]>h+!a[u-1][v]){
			f[u-1][v+1]=h+!a[u-1][v];
			if(a[u-1][v])q.push_front(make_pair(h+!a[u-1][v],make_pair(u-1,v+1)));
			else q.push_back(make_pair(h+!a[u-1][v],make_pair(u-1,v+1)));
		}
		if(u<N&&v<M&&f[u+1][v+1]>h+!a[u][v]){
			f[u+1][v+1]=h+!a[u][v];
			if(a[u][v])q.push_front(make_pair(h+!a[u][v],make_pair(u+1,v+1)));
			else q.push_back(make_pair(h+!a[u][v],make_pair(u+1,v+1)));
		}
		if(u<N&&v>0&&f[u+1][v-1]>h+!a[u][v-1]){
			f[u+1][v-1]=h+!a[u][v-1];
			if(a[u][v-1])q.push_front(make_pair(h+!a[u][v-1],make_pair(u+1,v-1)));
			else q.push_back(make_pair(h+!a[u][v-1],make_pair(u+1,v-1)));
		}
	}
	if(D==-1)cout<<"NO SOLUTION\n";
	else cout<<D<<'\n';
	return 0;
}