/*
Codeforces
239D
*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int N,H,a[100000],mx=-1;
bool f=0;
int main(){
	cin>>N>>H;
	for(int i=0;i<N;++i){
		cin>>a[i];if(mx==-1||a[i]<a[mx])mx=i;
	}
	sort(a,a+N);
	ll r=a[N-1]+a[N-2]-a[0]-a[1];
	ll x,y;
	if(N>2){
		x=max(a[N-1]+a[N-2],H+a[N-1]+a[0]);
		y=min(H+a[0]+a[1],a[1]+a[2]);
	}else{
		x=y=0;
	}
	if(x-y<r)r=x-y,f=1;
	cout<<r<<'\n';
	//cout<<x-y<<endl;
	for(int i=0;i<N;++i){
		if(f&&i==mx)cout<<'1';
		else cout<<'2';
		if(i!=N-1)cout<<' ';
	}
	cout<<'\n';
	return 0;
}
