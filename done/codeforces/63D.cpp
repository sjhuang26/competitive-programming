/*
Codeforces
63D
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	int a,b,c,d,N;cin>>a>>b>>c>>d>>N;
	int n[26];
	for(int i=0;i<N;++i)cin>>n[i];
	int D=max(b,d),A=a+c,R=a*b+c*d;
	char s[50][100];
	for(int i=0;i<D;++i)for(int j=0;j<A;++j)s[i][j]='.';
	int p=0;
	bool dir=a%2==0;
	for(int i=0;i<a;++i){
		if(dir){
			for(int j=0;j<b;++j){
				s[j][i]=p+'a';
				--n[p];if(n[p]==0)++p;
			}
		}else{
			for(int j=b-1;j>=0;--j){
				s[j][i]=p+'a';
				--n[p];if(n[p]==0)++p;
			}
		}
		dir=!dir;
	}
	for(int i=0;i<c;++i){
		if(dir){
			for(int j=0;j<d;++j){
				s[j][i+a]=p+'a';
				--n[p];if(n[p]==0)++p;
			}
		}else{
			for(int j=d-1;j>=0;--j){
				s[j][i+a]=p+'a';
				--n[p];if(n[p]==0)++p;
			}
		}
	}
	cout<<"YES\n";
	for(int i=0;i<D;++i){
		string ln;
		for(int j=0;j<A;++j){
			ln+=s[i][j];
		}
		cout<<ln<<'\n';
	}
	return 0;
}