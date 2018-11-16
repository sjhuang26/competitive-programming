/*
Codeforces
1009A
(contest)
*/
#include<iostream>
using namespace std;
int main(){
	int n,m;cin>>n>>m;
	int c[1000],a[1000];
	for(int i=0;i<n;++i)cin>>c[i];
	for(int i=0;i<m;++i)cin>>a[i];
	int r=0,d=0;
	for(int i=0;i<n;++i){
		if(a[d]>=c[i])++r,++d;
	}
	cout<<r<<'\n';
	return 0;
}
