/*
AC

Key ideas:
* We don't have to check every value of k - just the values where the candy distribution of at least one table changes. There are only 100 * sqrt(1e8) values to check in the worst case.
* For each value, use simple iteration to count the number of groups and update the answer from there.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>t;
int N,a[100],ans[100],T,d[100];
int main(){
	cin>>N;for(int i=0;i<N;++i)cin>>a[i],ans[i]=-1;
	for(int i=0;i<N;++i){
		int p=1;
		while(1){
			t.push_back(p);
			int x=a[i]/p;
			if(x==0)break;
			p=a[i]/x+1;
		}
	}
	sort(t.begin(),t.end());
	sort(a,a+N);
	T=t.size();
	for(int i=0;i<T;++i){
		if(i>0&&t[i]==t[i-1])continue;
		int row=0;
		for(int j=0;j<N;++j)d[j]=a[j]/t[i];
		// performance issues here?
		for(int j=0;j<N;++j){
			++row;
			if(j==N-1||d[j+1]!=d[j]){
				if(ans[row-1]==-1)ans[row-1]=t[i];
				row=0;
			}
		}
	}
	for(int i=0;i<N;++i)cout<<ans[i]<<'\n';
	return 0;
}