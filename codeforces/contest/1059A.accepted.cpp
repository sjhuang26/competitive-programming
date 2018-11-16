/*
Codeforces
1059A
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,l,a,r=0;
vector<pair<int,int>>s;
int main(){
	cin>>n>>l>>a;
	s.push_back({0,0});
	for(int i=0;i<n;++i){
		int x,y;cin>>x>>y;
		s.push_back({x,y});
	}
	s.push_back({l,0});
	sort(s.begin(),s.end());
	for(int i=1;i<=n+1;++i){
		int x=s[i].first-s[i-1].first-s[i-1].second;
		r+=x/a;
	}
	cout<<r<<'\n';
}
