/*
Codeforces
546D
*/
#include<iostream>
using namespace std;
typedef long long ll;
const int MX=5000000;
ll d[MX+1],p[MX+1]={},s[MX+1];
int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	for(int i=2;i<=MX;++i){
		if(p[i]==0){
			int k=0;
			for(int j=i;j<=MX;j+=i){
				p[j]=++k;
			}
		}
	}
	ll cs=0;
	d[1]=0;
	for(int i=2;i<=MX;++i){
		d[i]=1+d[p[i]];
		//cout<<i<<' '<<p[i]<<' '<<d[i]<<'\n';
		cs+=d[i];
		s[i]=cs;
	}
	int T;cin>>T;
	for(int t=0;t<T;++t){
		int a,b;cin>>a>>b;
		cout<<s[a]-s[b]<<'\n';
	}
	return 0;
}
