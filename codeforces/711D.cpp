/*
Codeforces
711D
*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int MD=1e9+7,MX=2*1e5;
int g[MX],f[MX],t[MX];
int mep(int a,int b,int m){
	
	ll r=1,im=a;
	for(int i=0;i<32;++i){
		if((b&(1<<i))!=0){
			r*=im;
			r%=m;
		}
		im*=im;
		im%=m;
	}
	//cout<<a<<' '<<b<<' '<<m<<' '<<r<<endl;
	return r;
}
int main(){
	int V;cin>>V;
	for(int i=0;i<V;++i)cin>>g[i],--g[i],f[i]=-1;
	int fre=V;
	vector<int>cyc;
	for(int i=0;i<V;++i){
		int tm=0,u=i;
		while(1){
			if(f[u]==-1){
				f[u]=i;
				t[u]=tm;
			}else if(f[u]==i){
				cyc.push_back(tm-t[u]);
				fre-=cyc.back();
				break;
			}else{
				break;
			}
			++tm;
			u=g[u];
		}
	}
	ll r=mep(2,fre,MD);
	for(int i:cyc){
		r*=((ll)mep(2,i,MD)-2+MD)%MD;
		r%=MD;
	}
	cout<<r<<'\n';
	return 0;
}
