/*
Codeforces
182D
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
	string a,b;cin>>a>>b;
	int A=a.size(),B=b.size();
	int S=min(A,B),r=0;
	for(int i=1;i<=S;++i){
		if(A%i!=0||B%i!=0)continue;
		bool w=1;
		for(int j=0;j<i;++j)if(a[j]!=b[j]){
			w=0;
			break;
		}
		if(!w)continue;
		for(int j=0;j<A;++j)if(a[j]!=a[j%i]){
			w=0;
			break;
		}
		if(!w)continue;
		for(int j=0;j<B;++j)if(b[j]!=b[j%i]){
			w=0;
			break;
		}
		if(!w)continue;
		++r;
		//cout<<'s'<<i<<endl;
	}
	cout<<r<<'\n';
	return 0;
}
