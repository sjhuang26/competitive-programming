/*
Algorithm practice
Segment tree
Iteration 1
7/21/2018
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int>t;
int N,P;
void change(int u,int v){
	int x=P+u;
	t[x]=v;
	do{
		x/=2;
		t[x]=t[2*x]+t[2*x+1];
	}while(x!=1);
}
int getrange(int a,int b){
	int r=0;
	a+=P;b+=P;
	while(a<=b){
		//cout<<a<<' '<<b<<endl;
		if(a%2==1)r+=t[a++];
		if(b%2==0)r+=t[b--];
		a/=2;b/=2;
	}
	return r;
}
int main(){
	P=1;cin>>N;
	while(P<N)P*=2;
	t=vector<int>(2*P);
	for(int i=0;i<N;++i)cin>>t[P+i];
	int Q;cin>>Q;
	for(int t=0;t<Q;++t){
		char ty;int u,v;cin>>ty>>u>>v;
		if(ty=='c'){
			change(u,v);
			cout<<"Changed"<<endl;
		}else if(ty=='q'){
			cout<<getrange(u,v)<<endl;
		}else{
			cout<<"?\n";
		}
	}
}
