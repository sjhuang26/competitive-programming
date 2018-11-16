/*
Codeforces
1059D
*/
#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
typedef long double ld;
ld a[100000],b[100000];
int N;
int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>a[i]>>b[i];
	}
	bool side=b[0]>0;
	for(int i=0;i<N;++i)if((b[i]>0)!=side){
		cout<<-1<<'\n';
		return 0;
	}
	if(!side){
		for(int i=0;i<N;++i){
			b[i]=-b[i];
		}
	}
	ld lo=0,hi=1e18,r=-1;
	int iters=0;
	while(iters<300){
		++iters;
		ld rd=(lo+hi)/2;
		//cout<<fixed<<setprecision(10)<<rd<<endl;
		ld ix=-1e18,ax=1e18;
		bool w=1;
		for(int i=0;i<N;++i){
			if(b[i]>2*rd){
				w=0;break;
			}
			ld dy=rd-b[i];
			ld dx=sqrt(2*rd*b[i]-b[i]*b[i]);
			//cout<<'b'<<b[i]<<endl;
			ld lf=a[i]-dx,rf=a[i]+dx;
			if(lf>ix)ix=lf;
			if(rf<ax)ax=rf;
		}
		if(w&&ix<=ax){
			r=rd;
			hi=rd;
		}else{
			lo=rd;
		}
	}
	if(r==-1){
		cout<<-1<<'\n';
	}else{
		cout<<fixed<<setprecision(10)<<r<<'\n';
	}
	return 0;
}