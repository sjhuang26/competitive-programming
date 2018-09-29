/*
Codeforces
368D
*/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int N,M,P,K,a[200000],b[200000],ra;
unordered_map<int,int>d,m;
vector<int>r;
int main(){
	cin>>N>>M>>P;
	for(int i=0;i<N;++i)cin>>a[i];
	for(int i=0;i<M;++i)cin>>b[i],++d[b[i]];
	K=d.size();
	for(int i=0;i<P;++i){
		ra=0;
		m.clear();
		int kx=min((ll)P*M,(ll)1e9);
		for(int j=i;j<N;j+=P){
			int k=j-kx;
			if(k>=0){
				k=a[k];
				if(m[k]==d[k])--ra;
				--m[k];
				if(m[k]==d[k])++ra;
			}
			k=a[j];
			if(m[k]==d[k])--ra;
			++m[k];
			if(m[k]==d[k])++ra;
			//cout<<ra<<' ';
			if(ra==K)r.push_back(j-kx+P+1);
		}
	}
	sort(r.begin(),r.end());
	cout<<r.size()<<'\n';
	for(int i=0;i<r.size();++i){
		cout<<r[i]<<(i==r.size()-1?'\n':' ');
	}
	return 0;
}
