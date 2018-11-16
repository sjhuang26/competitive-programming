/*
Codeforces
276C
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,Q,a[200000],b[200000],q[200001];
int main(){
	cin>>N>>Q;
	for(int i=0;i<N;++i)cin>>a[i];
	for(int i=0;i<N;++i)q[i]=0;
	for(int i=0;i<Q;++i){
		int x,y;cin>>x>>y;
		++q[x-1];
		--q[y];
	}
	int c=0;
	for(int i=0;i<N;++i){
		c+=q[i];
		b[i]=c;
		//cout<<':'<<c<<endl;
	}
	sort(b,b+N);
	sort(a,a+N);
	long long r=0;
	for(int i=0;i<N;++i){
		r+=(long long)b[i]*a[i];
	}
	cout<<r<<'\n';
	return 0;
}
