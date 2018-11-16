/*
UVa
193
*/
#include<iostream>
#include<vector>
using namespace std;
int s[100],rs[100],V,r=-1;
//long long ITER=0;
vector<int>e[100];
void fs(int n,int re){
	//++ITER;
	//cout<<n<<' '<<re<<' ';
	//for(int i=0;i<V;++i)cout<<s[i]<<' ';cout<<endl;
	//cout<<endl;
	if(re>r){
		r=re;for(int i=0;i<V;++i)rs[i]=s[i];
	}
	if(n==V)return;
	if(s[n]==0){
		s[n]=2;
		int redx=0,red[100];
		for(int i:e[n])if(s[i]==0){
			red[redx++]=i;
			s[i]=1;
		}
		fs(n+1,re+1);
		for(int i=0;i<redx;++i){
			s[red[i]]=0;
		}
		s[n]=0;
	}
	//s[n]=1;
	fs(n+1,re);
}
int main(){
	int T;cin>>T;
	for(int t=0;t<T;++t){
		int k;cin>>V>>k;
		r=-1;
		for(int i=0;i<V;++i)s[i]=0,e[i].clear();
		for(int i=0;i<k;++i){
			int a,b;cin>>a>>b;
			--a;--b;
			if(b>a)e[a].push_back(b);
			if(a>b)e[b].push_back(a);
		}
		fs(0,0);
		cout<<r<<'\n';
		vector<int>rw;
		for(int i=0;i<V;++i)if(rs[i]==2)rw.push_back(i+1);
		for(int i=0;i<rw.size();++i){
			cout<<rw[i];
			if(i!=rw.size()-1)cout<<' ';
		}
		cout<<'\n';
		//cout<<"ITER="<<ITER<<endl;
	}
	return 0;
}
