/*
Codeforces
659C
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
	int n,m;cin>>n>>m;
	set<int>a;
	for(int i=0;i<n;++i){
		int x;cin>>x;a.insert(x);
	}
	vector<int>r;
	for(int i=1;;++i){
		if(a.find(i)==a.end()){
			if(m-i<0)break;
			m-=i;
			r.push_back(i);
		}
	}
	int R=r.size();
	cout<<R<<'\n';
	for(int i=0;i<R;++i){
		cout<<r[i];
		if(i!=R-1)cout<<' ';
	}
	cout<<'\n';
	return 0;
}
