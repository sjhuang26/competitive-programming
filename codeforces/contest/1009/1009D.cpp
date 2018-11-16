/*
Codeforces
1009D
(contest)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[100001];
bool sv[100001]={};
int main(){
	int n,m;cin>>n>>m;//v e
	//vector<int>e,f;
	/*for(int i=1;i<=n;++i)a[i]=i;
	for(int i=2;i<=n;++i){
		if(!sv[i]){
			for(int j=i;j<=n;j+=i){
				sv[j]=1;
				a[j]=(ll)a[j]*(i-1)/(i);
				//e.push_back(i);
				//f.push_back(j);
			}
		}
	}
	ll r=0;
	for(int i=1;i<=n;++i)r+=a[i];
	cout<<r<<endl;
	cout<<(r>=m?"Possible":"Impossible")<<'\n';*/
	if(m<n-1){
		cout<<"Impossible\n";
		return 0;
	}
	vector<int>e,f;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i>j||i==j)continue;
			if(__gcd(i,j)==1){
				e.push_back(i);
				f.push_back(j);
				if(e.size()==m){
					cout<<"Possible"<<'\n';
					for(int i=0;i<m;++i){
						cout<<e[i]<<' '<<f[i]<<'\n';
					}
					return 0;
				}
			}
		}
	}
	cout<<"Impossible\n";
	return 0;
}
