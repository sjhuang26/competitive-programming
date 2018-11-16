/*
Codeforces
1059C
*/
#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int>r;
int main(){
	cin>>n;
	int l=n,d=1,m=1;//start*=1 end*=length length difference*=1 multiplier
	while(1){
		if(l==1){
			r.push_back(m);
			break;
		}else{
			int best=1e9,besti=-1;
			for(int i=2;i<=l;++i){
				int x=l-l/i;
				if(x<=best){
					best=x;
					besti=i;
				}
			}
			for(int i=0;i<best;++i){
				r.push_back(m);
			}
			m*=besti;
			l/=besti;
		}
	}
	for(int i=0;i<n;++i){
		cout<<r[i];
		if(i!=n-1)cout<<' ';
	}
	cout<<'\n';
	return 0;
}
