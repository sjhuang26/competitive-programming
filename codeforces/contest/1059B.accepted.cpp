/*
Codeforces
1059B
*/
#include<iostream>
#include<string>
using namespace std;
int N,M;
bool a[1000][1000],b[1000][1000]={};
int main(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		string x;cin>>x;
		for(int j=0;j<M;++j){
			a[i][j]=x[j]=='#';
		}
	}
	for(int i=1;i<N-1;++i){
		for(int j=1;j<M-1;++j){
			bool w=1;
			for(int k=-1+i;k<2+i;++k)for(int l=-1+j;l<2+j;++l){
				if(k==i&&l==j){
				}else{
					if(!a[k][l]){
						w=0;
						break;
					}
				}
			}
			if(w){
				for(int k=-1+i;k<2+i;++k)for(int l=-1+j;l<2+j;++l){
					if(k==i&&l==j){
					}else{
						b[k][l]=1;
					}
				}
			}
		}
	}
	bool r=1;
	for(int i=0;i<N;++i)for(int j=0;j<M;++j)if(a[i][j]!=b[i][j])r=0;
	cout<<(r?"YES":"NO")<<'\n';
	return 0;
}
