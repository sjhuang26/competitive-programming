/*
Codeforces
1009C
(contest)
*/
#include<iostream>
#include<limits>
using namespace std;
typedef numeric_limits<double>dbl;
typedef long long ll;
ll T(ll n){
	return n*(n+1)/2;
}
int main(){
	int n,m;cin>>n>>m;
	ll r=0;
	for(int i=0;i<m;++i){
		ll a;ll b;cin>>a>>b;
		r+=a*n;
		//cout<<r<<endl;
		if(b>=0){
			r+=b*T(n-1);
		}else if(n%2==1){
			r+=2*b*T((n-1)/2);
		}else{
			r+=b*T((n-2)/2)+b*T(n/2);
		}
		//cout<<r<<endl;
	}
	cout.precision(dbl::max_digits10);
	cout<<fixed<<(double)r/n<<'\n';
	return 0;
}
