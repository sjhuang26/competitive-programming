/*
UVa
12532
*/
#include<iostream>
using namespace std;
int t[300000];
int prd(int n){
	if(n==0)return 0;
	return n>0?1:-1;
}
int main(){
	while(true){
		int N,K,P=1;
		if(!(cin>>N))break;
		while(P<N)P*=2;
		cin>>K;
		for(int i=0;i<2*P;++i)t[i]=1;
		for(int i=0;i<N;++i){
			int x;cin>>x;
			t[i+P]=prd(x);
		}
		for(int i=P-1;i>=1;--i){
			t[i]=t[i*2]*t[i*2+1];
		}
		string r;
		for(int tt=0;tt<K;++tt){
			int a,b;char op;cin>>op>>a>>b;
			//for(int i=0;i<2*P;++i)cout<<t[i]<<' ';cout<<endl;
			if(op=='C'){
				a+=P-1;
				t[a]=prd(b);
				do{
					a/=2;
					t[a]=t[2*a]*t[2*a+1];
				}while(a!=1);
			}else if(op=='P'){
				a+=P-1;b+=P-1;
				int pr=1;
				while(a<=b){
					if(a%2==1)pr*=t[a],++a;
					if(b%2==0)pr*=t[b],--b;
					a/=2;b/=2;
				}
				r+=pr==0?'0':pr>0?'+':'-';
			}
		}
		cout<<r<<'\n';
	}
	return 0;
}
