/*
Codeforces
139D
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
	string a;cin>>a;int A=a.size(),r=-1,ri,rj;
	int b[10]={};
	for(int i=0;i<A;++i)++b[a[i]-'0'];
	for(int i=0;i<10;++i)for(int j=0;j<10;++j)if(i+j==10){
		int bta[10],btb[10];for(int k=0;k<10;++k)bta[k]=btb[k]=b[k];
		--bta[i];--btb[j];
		if(bta[i]<0||btb[j]<0)continue;
		int rn=0;
		for(int k=0;k<10;++k){
			int x=min(bta[k],btb[9-k]);
			bta[k]-=x;btb[9-k]-=x;
		}
		rn+=min(bta[0],btb[0]);
		if(rn>r)r=rn,ri=i,rj=j;
	}
	string ra,rb,rxa,rxb;
	int bta[10],btb[10];for(int k=0;k<10;++k)bta[k]=btb[k]=b[k];
	--bta[ri];--btb[rj];
	for(int k=0;k<10;++k){
		int x=min(bta[k],btb[9-k]);
		for(int i=0;i<x;++i)ra+='0'+k;
		for(int i=0;i<x;++i)rb+='0'+9-k;
		bta[k]-=x;btb[9-k]-=x;
	}
	ra+='0'+ri;
	rb+='0'+rj;
	//cout<<bta[0]<<' '<<btb[0]<<endl;
	int zc=min(bta[0],btb[0]);
	for(int i=0;i<min(bta[0],btb[0]);++i)ra+='0',rb+='0';
	bta[0]-=zc;
	btb[0]-=zc;
	for(int k=0;k<10;++k){
		for(int i=0;i<bta[k];++i)rxa+='0'+k;
		for(int i=0;i<btb[k];++i)rxb+='0'+k;
	}
	cout<<rxa+ra<<'\n'<<rxb+rb<<'\n';
	return 0;
}
