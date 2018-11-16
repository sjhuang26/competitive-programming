/*
Codeforces
9D
*/
#include<iostream>
using namespace std;
typedef long long ll;
ll d[36][36],N,H;
ll dp(int n,int h){
	//cout<<n<<h<<endl;
	if(n<0&&h<0)return 0;
	if(n==0)return h==0;
	if(d[n][h]!=-1)return d[n][h];
	ll r=0;
	for(int i=0;i<=n-1;++i){
		for(int j=0;j<=h-1;++j){
			r+=dp(i,j)*dp(n-1-i,h-1);
		}
		for(int j=0;j<h-1;++j){
			r+=dp(i,h-1)*dp(n-1-i,j);
		}
	}
	return d[n][h]=r;
}
int main(){
	cin>>N>>H;
	for(int i=0;i<=N;++i)for(int j=0;j<=N;++j)d[i][j]=-1;
	ll r=0;
	for(int i=H;i<=N;++i){
		r+=dp(N,i);
	}
	/*for(int i=0;i<=N;++i){
		for(int j=0;j<=N;++j)cout<<d[i][j]<<' ';
		cout<<endl;
	}*/
	cout<<r<<'\n';
	return 0;
}
