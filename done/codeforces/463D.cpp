/*
Codeforces
463D
*/
#include<iostream>
using namespace std;
int main(){
	int N,K;cin>>N>>K;
	int a[5][1000],ps[5][1000],d[1000];
	for(int i=0;i<K;++i)for(int j=0;j<N;++j)cin>>a[i][j],--a[i][j],ps[i][a[i][j]]=j;
	int r=1;
	for(int i=0;i<N;++i){
		d[i]=1;
		for(int j=0;j<i;++j){
			bool w=1;
			for(int k=0;k<K;++k){
				if(ps[k][a[0][j]]>ps[k][a[0][i]]){
					w=0;
					break;
				}
			}
			if(w)d[i]=max(d[i],d[j]+1);
		}
		r=max(r,d[i]);
		//cout<<'d'<<d[i]<<endl;
	}
	cout<<r<<'\n';
	return 0;
}
