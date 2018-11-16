/*
Codeforces
1009E
(upsolved)
(can't debug)
*/
#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
int a[1000005];
int pwr[1000005];
int main(){
	int A;cin>>A;
	for(int i=0;i<A;++i)cin>>a[i];
	int wr=1;
	for(int i=0;i<=A;++i){
		pwr[i]=wr;
		wr*=2;
		wr%=MOD;
	}
	ll r=0;
	for(int i=1;i<A;++i){
		r+=(ll)a[i-1]*pwr[A-i-1]*(A-i+1);
		r%=MOD;
		//cout<<r<<endl;
	}
	for(int i=1;i<A;++i){
		r+=(ll)a[i-1]*pwr[A-i-1];
		r%=MOD;
	}
	r+=a[A-1];
	r%=MOD;
	cout<<r<<'\n';
}
