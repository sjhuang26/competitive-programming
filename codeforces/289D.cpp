/*
Codeforces
289D
(uses generator)
*/
#include<iostream>
using namespace std;
const int ra[8]={1,2,9,64,625,7776,117649,2097152},MD=1000000007;
int main(){
	int n,k;cin>>n>>k;
	long long r=ra[k-1];
	for(int i=0;i<n-k;++i){
		r*=n-k;
		r%=MD;
	}
	cout<<r<<'\n';
	return 0;
}
