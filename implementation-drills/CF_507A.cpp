#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,k,t=0,a[100];cin>>n>>k;
	vector<int>r;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i){
		int x=1e9,y=-1;
		for(int j=0;j<n;++j){
			if(a[j]<x)x=a[j],y=j;
		}
		if(t+x>k){
			t=i;break;
		}
		t+=x;
		r.push_back(y+1);
		a[y]=1e9;
	}
	cout<<r.size()<<'\n';
	if(r.size()==0)return 0;
	for(int i=0;i<r.size();++i){
		cout<<r[i];if(i!=r.size()-1)cout<<' ';
	}cout<<'\n';
	return 0;
}