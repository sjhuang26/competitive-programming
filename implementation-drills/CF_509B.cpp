#include<iostream>
using namespace std;
int main(){
	int n,k,a[100],b[100]={},r[100];cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>a[i];++b[a[i]-1];
	}
	bool w=1;int c=-1;--k;
	for(int i=0;i<n;++i){
		//if(c==-1&&b[i]>0)c=i;
		if(c!=-1&&i-c>1)--k,c=-1;
		if(c==-1&&b[i]>0)c=i;
		if(k<0){
			w=0;break;
		}
		r[i]=k;
		c=-1;
	}
	if(w){
		cout<<"YES\n";
		for(int i=0;i<n;++i){
			for(int j=0;j<a[i];++j){
				cout<<r[j]+1;
				if(j!=a[i]-1)cout<<' ';
			}cout<<'\n';
		}
	}else{
		cout<<"NO\n";
	}
	return 0;
}