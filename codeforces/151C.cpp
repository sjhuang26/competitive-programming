/*
Codeforces
151C
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
ll div(ll a){
	int B=min((ll)sqrt(a)+1,a-1);
	for(int i=2;i<=B;++i){
		if(a%i==0)return i;
	}
	return -1;
}
int main(){
	ll a;cin>>a;
	vector<ll>f;
	while(true){
		ll x=div(a);
		if(x==-1)break;
		a/=x;
		f.push_back(x);
		//cout<<x<<' ';
	}
	f.push_back(a);
	if(f.size()==1)cout<<"1\n0\n";
	if(f.size()==2)cout<<"2\n";
	if(f.size()>2)cout<<"1\n"<<f[0]*f[1]<<'\n';
	return 0;
}
