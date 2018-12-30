/*
COCI 13-parovi

Partial credit (debugging issues)

Main ideas:
* Find the distribution of digits for each value / possible digit / position.
* Use this information to calculate the sum of all the possible pairs.
*/
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
int N;
const int M=1e9+7;
struct o{
	string s;
	int p[50000],n[50000],d[10];
};
int pt[50000],df[10][10];
o a,b;
void process(o&u){
	u.s=string(N-u.s.size(),'0')+u.s;
	ll x=0;
	for(int i=0;i<N;++i)u.n[i]=x,x=(10*x+u.s[i]-'0')%M;
	x=0;
	for(int i=N-1;i>=0;--i)u.p[i]=x,x=(((u.s[i]-'0')*pt[N-i-1])%M+x)%M;
	//for(int i=0;i<N;++i)cout<<u.n[i]<<' '<<u.p[i]<<endl;
}
void find_distr(o&u,int j,bool incl){
	for(int i=0;i<10;++i){
		if(i<u.s[j]-'0'){
			u.d[i]=((ll)(u.n[j]+1)*pt[N-j-1])%M;
		}else if(i==u.s[j]-'0'){
			u.d[i]=(((ll)u.n[j]*pt[N-j-1])+incl+u.p[j])%M;
		}else{
			u.d[i]=((ll)u.n[j]*pt[N-j-1])%M;
		}
	}
}
ll calc(o&u,o&v,bool uincl,bool vincl){
	ll res=0;
	for(int i=0;i<N;++i){
		find_distr(u,i,uincl);
		find_distr(v,i,vincl);
		//for(int i=0;i<10;++i){
		//  cout<<u.d[i]<<' '<<v.d[i]<<endl;
		//}
		for(int i=0;i<10;++i)for(int j=0;j<10;++j){
			res+=((ll)df[i][j]*(((ll)u.d[i]*v.d[j])%M))%M;
			res%=M;
		}
	}
	return res%M;
}
int main(){
	cin>>ws>>a.s>>ws>>b.s;
	N=max(a.s.size(),b.s.size());
	ll x=1;
	for(int i=0;i<N;++i)pt[i]=x,x*=10,x%=M;
	for(int i=0;i<10;++i)for(int j=0;j<10;++j)df[i][j]=abs(i-j);
	process(a);
	process(b);
	cout<<(calc(b,b,1,1)-2*calc(a,b,0,1)+calc(a,a,0,0))%M<<'\n';
	return 0;
}