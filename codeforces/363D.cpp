/*
Codeforces
363D
*/
#include<iostream>
#include<algorithm>
int b[100000],c[100000];
using namespace std;
typedef long long ll;
int main(){
	int N,M,A;cin>>N>>M>>A;
	for(int i=0;i<N;++i)cin>>b[i];
	for(int i=0;i<M;++i)cin>>c[i];
	sort(b,b+N);sort(c,c+M);
	int lo=0,hi=min(N,M),r=0,rp=0;
	while(lo<=hi){
		//cout<<lo<<' '<<hi<<endl;
		int md=(lo+hi)/2;
		ll bu=0,p=0;
		for(int i=0;i<md;++i){
			bu+=max(0,c[i]-b[N-md+i]);
			p+=c[i]-max(0,c[i]-b[N-md+i]);
		}
		//cout<<'b'<<bu<<endl;
		if(bu<=(ll)A){
			p-=min(p,(ll)A-bu);
			r=md;rp=p;
			lo=md+1;
		}else{
			hi=md-1;
		}
	}
	cout<<r<<' '<<rp<<'\n';
	return 0;
}
