/*
Baltic 15-net (accepted, looked at solution)

Key ideas:
- Simply link the ith leaf node to the i+(# of leaves)/2 node.
- Account for the case where (# of leaves) is odd.

*/
#include<iostream>
#include<vector>
using namespace std;
vector<int>s;
vector<vector<int>>t;//1 IDX
bool f[500005]={};
int N;
void dfs(int u){
	if(f[u])return;
	f[u]=1;
	if(t[u].size()==1)s.push_back(u);
	for(int&i:t[u])dfs(i);
}
int main(){
	cin>>N;
	for(int i=0;i<=N+5;++i)t.push_back(vector<int>());
	for(int i=0;i<N-1;++i){
		int a,b;cin>>a>>b;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	dfs(1);
	int k=s.size();
	if(k%2){
		cout<<k/2+1<<'\n';
		for(int i=0;i<k/2;++i){
			cout<<s[i]<<' '<<s[i+k/2+1]<<'\n';
		}
		cout<<s[k/2]<<' '<<1<<'\n';
	}else{
		cout<<k/2<<'\n';
		for(int i=0;i<k/2;++i){
			cout<<s[i]<<' '<<s[i+k/2]<<'\n';
		}
	}

	// free memory
	vector<vector<int>>().swap(t);
	vector<int>().swap(s);

	return 0;
}