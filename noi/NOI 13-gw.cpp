#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int>ii;
int N,a[1000000],ch=0,ans=-1;
vector<ii>b;
//0=land,1=no land
bool f[1000000]={};
int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>a[i];
		b.push_back({a[i],i});
	}
	sort(b.begin(),b.end());
	if(b[0].first>0)ans=1;
	for(int i=0;i<N;++i){
		int x=b[i].second;
		if(x!=0)ch+=(f[x]==f[x-1]?1:-1);
		if(x!=N-1)ch+=(f[x]==f[x+1]?1:-1);
		f[x]=1;
		if((i==N-1)||(b[i].first!=b[i+1].first)){
			int isl;
			if(f[0]){
				//011223344...
				isl=ch/2+ch%2;
			}else{
				//112233445...
				isl=ch/2+1;
			}
			ans=max(ans,isl);
		}
	}
	// deallocate memory of vector (workaround for memory bug?)
	// OK... looks like OJ.UZ has a bug where memory doesn't get freed properly.
	vector<ii>().swap(b);

	cout<<ans<<'\n';return 0;
}