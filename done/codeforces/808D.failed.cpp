/*
Codeforces
808D
(failed)
*/
#include<iostream>
#include<set>
using namespace std;
typedef long long ll;
int a[100000];
/*int finda(ll x,int lo,int hi){
	cout<<x<<' '<<lo<<' '<<hi<<endl;
	while(lo<=hi){
		int md=(lo+hi)/2;
		if(x==a[md]){
			return md;
		}else if(x<a[md]){
			hi=md-1;
		}else{
			lo=md+1;
		}
	}
	return -1;
}*/
multiset<int>bega;multiset<int>enda;
int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int A;cin>>A;
	ll S=0;
	
	for(int i=0;i<A;++i)cin>>a[i],S+=a[i],enda.insert(a[i]);
	if(S%2==0&&A!=1){
		S/=2;
		ll cs=0;
		for(int i=0;;++i){
			ll ps=llabs(cs-S);
			if(ps>1e9)continue;
			//ps=(ps%2==1?-1:ps/2);
			//cout<<'P'<<ps<<endl;
			if(cs==S||cs>S&&bega.find(ps)!=bega.end()||cs<S&&enda.find(ps)!=enda.end()){
				//cout<<cs<<' '<<S<<' '<<i<<endl;
				cout<<"YES\n";
				return 0;
			}
			if(i==A)break;
			cs+=a[i];
			bega.insert(a[i]);
			enda.erase(enda.find(a[i]));
		}
	}
	cout<<"NO\n";
	return 0;
}