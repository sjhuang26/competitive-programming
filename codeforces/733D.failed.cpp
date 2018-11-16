/*
Codeforces
733D
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
int main(){
	int N,tm[3],la=-1,lb=-1,cn=0,ra=0,r=0;
	vector<tuple<int,int,int,int>>s;
	vector<int>dx,rd;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>tm[0]>>tm[1]>>tm[2];
		sort(tm,tm+3);
		s.push_back({tm[1],tm[2],tm[0],i});
	}
	sort(s.begin(),s.end(),greater<tuple<int,int,int,int>>());
	//la lb cn ra r dx rd
	for(auto i:s){
		int u=get<0>(i),v=get<1>(i),w=get<2>(i),d=get<3>(i);
		//cout<<u<<' '<<v<<' '<<w<<' '<<d<<endl;
		if(u==la&&v==lb){
			++cn;
			dx.push_back(d);
			if(cn<=2){
				ra+=w;
				if(ra>r)r=ra,rd=dx;
			}
		}else{
			dx.clear();
			dx.push_back(d);
			ra=0;cn=1;
		}
		la=u;lb=v;
	}
	cout<<rd.size()<<'\n';
	for(int i=0;i<rd.size();++i){
		cout<<rd[i]+1;if(i!=rd.size()-1)cout<<' ';
	}
	cout<<'\n';
	return 0;
}
