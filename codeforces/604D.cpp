/*
Codeforces
604D
*/
#include<iostream>
using namespace std;
typedef long long ll;
const int M=1e9+7;int p,k;
ll mpw(int a,int b){
	if(b==0)return 1;
	return (mpw(a,b-1)*a)%M;
}
int main(){
	cin>>p>>k;
	if(k==0)cout<<mpw(p,p-1);
	else if(k==1)cout<<mpw(p,p);
	else{
		int r=1;ll x=k;
		while(x!=1){
			++r;x*=k;x%=p;
			//cout<<x<<endl;
		}
		cout<<mpw(p,(p-1)/r);
	}
	cout<<'\n';
	return 0;
}
