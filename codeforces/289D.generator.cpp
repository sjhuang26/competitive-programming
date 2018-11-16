#include<iostream>
using namespace std;
typedef long long ll;
int r;
int i,s[8];
bool f[8];
void rec(int n){
	if(n==i){
		for(int j=0;j<i;++j){
			for(int k=0;k<8;++k)f[k]=0;
			int p=j;
			while(p!=0&&!f[p])f[p]=1,p=s[p];
			if(p!=0){
				return;
			}
		}
		++r;
	}else{
		for(int j=0;j<i;++j){
			s[n]=j;
			rec(n+1);
		}
	}
}
int main(){
	for(i=1;i<=8;++i){
		r=0;
		rec(0);
		cout<<r<<endl;
	}
}
