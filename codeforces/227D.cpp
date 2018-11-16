/*
Codeforces
227D
*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[100001],me[100001];
int ar[100000];
int main(){
	int N,Q;cin>>N;
	for(int i=0;i<N;++i)cin>>ar[i];
	sort(ar,ar+N);
	a[0]=0;
	for(int i=0;i<N;++i){
		a[i+1]=a[i]+ar[i];
	}
	for(int i=0;i<=100000;++i)me[i]=-1;
	cin>>Q;
	for(int i=0;i<Q;++i){
		int q;cin>>q;
		ll r=0;
		if(me[q]!=-1)r=me[q];
		else{
			for(ll ls=1,lc=0,lp=N;lp>=0;++lc,ls*=q){
				int x=(int)lp;
				lp-=ls;
				r+=(a[x]-a[max(-1LL,lp-1)+1])*lc;
				//cout<<ls<<' '<<lc<<' '<<lp<<endl;
			}
		}
		me[q]=r;
		cout<<r;
		if(i!=Q-1)cout<<' ';
	}
	cout<<'\n';
}
