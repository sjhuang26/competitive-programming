/*
Codeforces
122D
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
	int N,K,i=0,p=0;
	bool w=0,cyc=0;
	cin>>N>>K;
	string a;cin>>a;
	for(;i<K;++i){
		//cout<<a<<endl;
		int pl=p;
		while(p<N-1&&!(a[p]=='4'&&a[p+1]=='7'))++p;
		if(p==N-1)break;
		if(p==pl&&w){
			cyc=1;break;
		}
		//odd=4 even=7
		if((p+1)%2){
			a[p]=a[p+1]='4';
			w=0;
		}else{
			a[p]=a[p+1]='7';
			if(p>0)--p;
			w=1;
		}
		//cout<<a<<endl;
	}
	if(cyc){
		//cout<<"CYC"<<endl;
		int M=K-i;
		a[p]='4';a[p+2]='7';
		a[p+1]=(M%2?'4':'7');
	}
	cout<<a<<'\n';
	return 0;
}
