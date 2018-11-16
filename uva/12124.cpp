/*
UVa
12124
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
typedef pair<int,int>ii;
typedef long long ll;
int main(){
	int T;cin>>T;
	for(int t=0;t<T;++t){
		int N,B;cin>>N>>B;
		map<string,int>na;
		vector<vector<ii>>s;
		for(int i=0;i<N;++i){
			string a,b;int p,q,x;
			cin>>a>>b>>p>>q;
			if(na.find(a)==na.end()){
				x=na.size();
				na[a]=x;
				s.push_back(vector<ii>());
			}else{
				x=na[a];
			}
			s[x].push_back({p,q});
		}
		int lo=-1,hi=1e9,sol=-1;
		while(lo<=hi){
			int md=(lo+hi)/2;
			ll x=0;
			bool w=1;
			for(auto i:s){
				int mc=2e9;
				for(auto j:i){
					if(j.second>=md)mc=min(mc,j.first);
				}
				if(mc==2e9){
					w=0;break;
				}
				else x+=mc;
				if(x>B){
					w=0;break;
				}
			}
			if(w){
				sol=md;
				lo=md+1;
			}else{
				hi=md-1;
			}
		}
		cout<<sol<<'\n';
	}
}
