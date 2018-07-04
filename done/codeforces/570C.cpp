/*
Codeforces
570C
*/
#include<iostream>
using namespace std;
int main(){
	int N,M;cin>>N>>M;
	string a;cin>>a;
	int r=0;
	for(int i=1;i<N;++i){
		if(a[i]=='.'&&a[i-1]=='.')++r;
	}
	for(int i=0;i<M;++i){
		int b;char c;cin>>b>>c;
		--b;
		if(b!=0)r-=a[b-1]=='.'&&a[b]=='.';
		if(b!=N-1)r-=a[b]=='.'&&a[b+1]=='.';
		a[b]=c;
		if(b!=0)r+=a[b-1]=='.'&&a[b]=='.';
		if(b!=N-1)r+=a[b]=='.'&&a[b+1]=='.';
		cout<<r<<'\n';
	}
	return 0;
}