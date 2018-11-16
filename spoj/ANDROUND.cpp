/*
SPOJ
ANDROUND
*/
#include<iostream>
using namespace std;
bool a[32][20000];
int r[20000];
int main(){
	int T;cin>>T;
	for(int t=0;t<T;++t){
		int N,K;cin>>N>>K;
		for(int i=0;i<N;++i){
			int x;cin>>x;
			for(int j=0;j<31;++j){
				a[j][i]=(x&(1<<j))!=0;
			}
			r[i]=0;
		}
		for(int j=0;j<31;++j){
			int fz=-1;int lz=-1;
			for(int i=0;i<N;++i){
				//cout<<a[j][i]<<' ';
				if(!a[j][i]){
					if(fz==-1){
						fz=lz=i;
					}else{
						//cout<<fz<<' '<<lz<<endl;
						for(int k=lz+K+1;k<=i-1-K;++k)r[k]|=(1<<j);
						lz=i;
					}
				}
			}
			if(fz!=-1){
				//cout<<fz<<'#'<<lz<<endl;
				for(int k=lz+1+K;k<=fz-1-K+N;++k)r[k%N]|=(1<<j);
			}else{
				//everything +
				for(int k=0;k<N;++k)r[k]|=(1<<j);
			}
			//cout<<endl;
		}
		for(int i=0;i<N;++i){
			cout<<r[i];if(i!=N-1)cout<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
