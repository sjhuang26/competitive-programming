/*
UVa
501
*/
#include<set>
#include<iostream>
#include<vector>
using namespace std;
int a[30000];
int main(){
	int T;cin>>T;
	while(T--){
		int M,N;cin>>M>>N;
		for(int i=0;i<M;++i)cin>>a[i];
		multiset<int>s;
		s.insert(a[0]);
		multiset<int>::iterator it=s.begin();
		int sz=1;
		bool isf=1;
		for(int i=0;i<N;++i){
			int u;cin>>u;
			while(sz<u){
				s.insert(a[sz]);
				if(*it>a[sz])--it;
				++sz;
			}
			if(isf)isf=0;
			else ++it;
			cout<<*it<<'\n';
		}
		if(T!=0)cout<<'\n';
	}
	return 0;
}
