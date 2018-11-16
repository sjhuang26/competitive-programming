/*
Codeforces
58D
*/
#include<iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;
string a[10000];
int main(){
	int N;cin>>N;
	vector<set<string>>as(11);
	int S=0;
	set<string>f;
	//cout<<1<<endl;
	for(int i=0;i<N;++i){
		cin>>ws;
		string x;cin>>x;
		as[x.size()].insert(x);
		a[i]=x;
		S+=x.size();
	}
	S/=N/2;
	char c;cin>>c;
	//cout<<2<<endl;
	for(int i=0;i<N;++i){
		f.insert(a[i]+c);
	}
	//cout<<3<<endl;
	for(int i=0;i<N/2;++i){
		//cout<<5<<endl;
		auto xr=f.begin();
		string x=*xr;
		x.pop_back();
		f.erase(xr);
		as[x.size()].erase(x);
		//cout<<'d'<<S<<' '<<x<<endl;
		auto yr=as[S-x.size()].begin();
		string y=*yr;
		f.erase(y+c);
		as[y.size()].erase(yr);
		cout<<x+c+y<<'\n';
	}
	//cout<<4<<endl;
	return 0;
}
