/*
Codeforces
43D
*/
#include<iostream>
using namespace std;
int main(){
	// COPY AND PASTE FOR THE WIN!
	int n,m,rt=-1,ct;cin>>n>>m;
	int N=n,M=m;
	bool en=n%2==0,em=m%2==0;
	if(n==1&&m==2){
		cout<<"0\n1 1\n1 2\n1 1\n";
		return 0;
	}else if(n==2&&m==1){
		cout<<"0\n1 1\n2 1\n1 1\n";
		return 0;
	}else	if(n==1){
		rt=1;ct=M;
		cout<<1<<'\n'<<rt<<' '<<ct<<" 1 1\n";
		for(int i=1;i<=M;++i){
			cout<<1<<' '<<i<<'\n';
		}
	}else if(m==1){
		rt=N;ct=1;
		cout<<1<<'\n'<<rt<<' '<<ct<<" 1 1\n";
		for(int i=1;i<=N;++i){
			cout<<i<<' '<<1<<'\n';
		}
	}else if(en&&em||en&&!em){
		cout<<0<<'\n';
		cout<<"1 1\n";
		for(int i=1;i<=N;++i){
			if(i%2==1){
				for(int j=2;j<=M;++j){
					cout<<i<<' '<<j<<'\n';
				}
			}else{
				for(int j=M;j>=2;--j){
					cout<<i<<' '<<j<<'\n';
				}
			}
		}
		for(int i=N;i>=2;--i)cout<<i<<' '<<1<<'\n';
	}else if(!en&&em){
		cout<<0<<'\n';
		cout<<"1 1\n";
		for(int i=1;i<=M;++i){
			if(i%2==1){
				for(int j=2;j<=N;++j){
					cout<<j<<' '<<i<<'\n';
				}
			}else{
				for(int j=N;j>=2;--j){
					cout<<j<<' '<<i<<'\n';
				}
			}
		}
		for(int i=M;i>=2;--i)cout<<1<<' '<<i<<'\n';
	}else{
		rt=N;ct=M;
		cout<<1<<'\n'<<rt<<' '<<ct<<" 1 1\n";
		for(int i=1;i<=M;++i){
			if(i%2==1){
				for(int j=1;j<=N;++j){
					cout<<j<<' '<<i<<'\n';
				}
			}else{
				for(int j=N;j>=1;--j){
					cout<<j<<' '<<i<<'\n';
				}
			}
		}
	}
	cout<<"1 1\n";
	return 0;
}
