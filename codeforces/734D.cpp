/*
Codeforces
734D
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int N,S,T;cin>>N>>S>>T;
	bool w[8]={};
	ll m[8];for(int i=0;i<8;++i)m[i]=1e10;
	for(int i=0;i<N;++i){
		char pc;ll x,y,s;cin>>pc>>x>>y;x-=S;y-=T;
		s=abs(x)+abs(y);
		if(s<m[0]&&x==0&&y>0)w[0]=pc=='R'||pc=='Q',m[0]=s;
		if(s<m[1]&&x==0&&y<0)w[1]=pc=='R'||pc=='Q',m[1]=s;
		if(s<m[2]&&y==0&&x>0)w[2]=pc=='R'||pc=='Q',m[2]=s;
		if(s<m[3]&&y==0&&x<0)w[3]=pc=='R'||pc=='Q',m[3]=s;
		if(s<m[4]&&x==y&&x>0)w[4]=pc=='B'||pc=='Q',m[4]=s;
		if(s<m[5]&&x==y&&x<0)w[5]=pc=='B'||pc=='Q',m[5]=s;
		if(s<m[6]&&-x==y&&x>0)w[6]=pc=='B'||pc=='Q',m[6]=s;
		if(s<m[7]&&-x==y&&x<0)w[7]=pc=='B'||pc=='Q',m[7]=s;
	}
	bool r=0;
	for(int i=0;i<8;++i)if(w[i])r=1;
	cout<<(r?"YES":"NO")<<'\n';
	return 0;
}
