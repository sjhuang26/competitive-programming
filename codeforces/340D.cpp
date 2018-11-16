/*
Codeforces
340D
*/
#include<iostream>
using namespace std;
int d[100001],a[100000];
int main(){
	int A,r=0;cin>>A;
	for(int i=0;i<A;++i){
		cin>>a[i];
		int lo=1,hi=r;
		while(lo<=hi){
			int md=(lo+hi)/2;
			if(a[d[md]]<=a[i])lo=md+1;
			else hi=md-1;
		}
		// result=lo=searchvalue+1
		if(lo>r)r=lo;
		d[lo]=i;
	}
	cout<<r<<'\n';
	return 0;
}
