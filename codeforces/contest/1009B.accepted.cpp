/*
Codeforces
1009B
(contest)
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
	string a;cin>>a;
	int A=a.size();
	int c=0;
	for(int i=0;i<A;++i)c+=a[i]=='1';
	bool x=1;
	string r;
	for(int i=0;i<A;++i){
		if(a[i]=='0'){
			r+='0';
		}else if(a[i]=='2'){
			if(x){
				x=0;
				for(int j=0;j<c;++j)r+='1';
			}
				r+='2';
		}
	}
	if(x)for(int i=0;i<c;++i)r+='1';
	cout<<r<<'\n';
	return 0;
}
