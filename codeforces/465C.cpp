/*
Codeforces
465C
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	int A,P;cin>>A>>P;
	cin>>ws;
	string a;cin>>a;
	string r;
	bool w=0;
	for(int i=A-1;i>=0;--i){
		for(char j=a[i]+1;j<'a'+P;++j){
			if((i-1<0||a[i-1]!=j)&&(i-2<0||a[i-2]!=j)){
				r=a;
				r[i]=j;
				w=1;
				for(int k=i+1;k<A;++k){
					w=0;
					for(char m='a';m<'a'+P;++m){
						if((k-1<0||r[k-1]!=m)&&(k-2<0||r[k-2]!=m)){
							r[k]=m;
							w=1;
							break;
						}
					}
					if(!w)break;
				}
			}
			if(w)break;
		}
		if(w)break;
	}
	if(w){
		cout<<r<<'\n';
	}else{
		cout<<"NO\n";
	}
	return 0;
}