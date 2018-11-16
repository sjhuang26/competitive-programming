/*
UVa
10419
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
vector<int>pr;
int N,T;
bool d[400][1000][14];//index n/sum t/count
//???
int pt[14];
auto&C=cout;
bool search(int id,int n,int t){
	//C<<id<<' '<<n<<' '<<t<<endl;
	if(n>N||t>T)return 0;
	if(n==N&&t==T)return 1;
	if(id==pr.size())return 0;
	if(d[id][n][t])return 0;
	d[id][n][t]=1;
	pt[t]=pr[id];
	return search(id+1,n+pr[id],t+1)||search(id+1,n,t);
}
bool comp(int a,int b){
	return to_string(a)<to_string(b);
}
int main(){
	pr.push_back(2);
	for(int i=3;i<300;++i){
		bool w=1;
		for(int j=2;j<i;++j)if(i%j==0){
			w=0;break;
		}
		if(w)pr.push_back(i),pr.push_back(i);
	}
	sort(pr.begin(),pr.end(),comp);
	int CASES=0;
	while(1){
		++CASES;
		cin>>N>>T;
		if(N==T&&T==0)break;
		memset(d,0,sizeof(d));
		C<<"CASE "<<CASES<<":\n";
		if(search(0,0,0)){
			for(int i=0;i<T;++i){
				C<<pt[i];
				if(i!=T-1)C<<'+';
			}
		}else{
			C<<"No Solution.";
		}
		C<<'\n';
	}
	return 0;
}
