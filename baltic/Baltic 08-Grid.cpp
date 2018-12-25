/*
Baltic 08-Grid
(accepted)

Key ideas:
* Use binary search to narrow down the possible range of the optimal value
* For each value selected by the binary search, iterate over all possible combinations of horizontal lines
* For each combination of horizontal lines, see if vertical lines can be placed so that the sums of the sub-rectangles created don't go over the value
*/
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
int N,M,R,S,a[18][18],b[18],b2[18],cs[18][19];
queue<string>sm;vector<string>sp;
bool can(int cutoff){
	for(auto&x:sp){
		memset(b,0,sizeof b);
		int n=0;bool fail=0;
		for(int i=0;i<M;++i){
			int u=0;
			bool w=1;
			for(int j=0;j<=R;++j){
				int v=x[j];
				b2[j]=cs[i][v]-cs[i][u];
				if(b[j]+b2[j]>cutoff)w=0;
				u=v;
			}
			if(!w){
				//cout<<cutoff<<'>'<<i<<endl;
				memset(b,0,sizeof b);
				++n;
			}
			for(int i=0;i<=R;++i)b[i]+=b2[i];
			if(*max_element(b,b+R+1)>cutoff)n=1e9;
			if(n>S){
				fail=1;break;
			}
		}
		if(!fail){
			//cout<<cutoff<<'=';
			//for(char&c:x)cout<<int(c)<<' ';cout<<endl;
			return 1;
		}
	}
	return 0;
}
int main(){
	cin>>N>>M>>R>>S;
	for(int i=0;i<N;++i)for(int j=0;j<M;++j)cin>>a[i][j];
	for(int i=0;i<M;++i){
		cs[i][0]=0;
		for(int j=1;j<=N;++j){
			cs[i][j]=cs[i][j-1]+a[j-1][i];
		}
	}
	for(int i=1;i<=N-R;++i)sm.push(string(1,i));
	while(!sm.empty()){
		auto x=sm.front();
		if(x.size()==R){
			sp.push_back(x+char(N));
			sm.pop();
			continue;
		}
		for(int i=x.back()+1;i<=N-(R-x.size());++i){
			sm.push(x+char(i));
		}
		sm.pop();
	}
	int lo=0,hi=1e9;
	while(lo<=hi){
		int md=(lo+hi)/2;
		if(can(md)){
			hi=md-1;
		}else{
			lo=md+1;
		}
	}
	cout<<hi+1<<'\n';
	return 0;
}