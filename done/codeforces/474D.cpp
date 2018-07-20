/*
Codeforces
474D
*/
#include<iostream>
using namespace std;
typedef long long ll;
int md=1000000007;
int no=100000;
int s[100001],a[100001];
int main(){
	int T,k;cin>>T>>k;
	s[0]=1;
	for(int i=1;i<=no;++i){
		if(i-k>=0){
			s[i]=(s[i-1]+s[i-k])%md;
		}else{
			s[i]=s[i-1];
		}
		//cout<<s[i]<<endl;
	}
	a[0]=s[0];
	for(int i=1;i<=no;++i){
		a[i]=(a[i-1]+s[i])%md;
		//cout<<a[i]<<endl;
	}
	for(int t=0;t<T;++t){
		int x,y;cin>>x>>y;
		cout<<((a[y]-a[x-1]+md)%md)<<'\n';
	}
	return 0;
}
