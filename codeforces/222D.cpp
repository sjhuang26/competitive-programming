/*
Codeofrces
222D
*/
#include<iostream>
#include<algorithm>
using namespace std;
int a[100000],b[100000];
int main(){
	int n,x;cin>>n>>x;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)cin>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	int p=0,ap=0,bp=0,pv=1e9;
	for(int i=n-1;i>=0;--i){
		while(p<n&&a[i]+b[p]<x)++p;
		if(p>=n)break;
		if(a[i]+b[p]<pv)pv=a[i]+b[p],ap=i,bp=p;
	}
	p=0;int r=1;
	//cout<<pv<<ap<<bp<<endl;
	for(int i=n-1;i>=0;--i){
		if(ap==i)continue;
		while(p==bp||p<n&&a[i]+b[p]<pv)++p;
		if(p>=n)break;
		++r;++p;
	}
	cout<<"1 "<<r<<'\n';
	return 0;
}
