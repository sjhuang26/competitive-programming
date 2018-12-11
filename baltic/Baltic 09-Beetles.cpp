/*
(accepted)
Author: Suhao Jeffrey Huang
Main ideas:
	* Use two DP arrays:
		l[j][k] --> the beetle has in total drunk everything in the interval [j, k] inclusive, and the beetle is at the jth (left) position: from this position, how many waters are **lost**?
		r[j][k] --> same, but the beetle is at the kth (right) position.
	* Perform N iterations. The ith iteration represents the case where i droplets have been drunk.
	* Each step of the DP is like:
		CURRENT_VALUE = min(CURRENT_VALUE, BROADER_RANGE_FROM_PREVIOUS + i * (DISTANCE_COVERED_BY_MOVEMENT))
	* 0 is included as a "droplet" in the DP but the code is written so that this doesn't affect the total
*/
#include<iostream>
#include<algorithm>
using namespace std;
int N,M,a[301],l[2][301][301]={},r[2][301][301]={};
const int mx=1e9;
int main(){
	cin>>N>>M;
	for(int i=0;i<N;++i)cin>>a[i];
	a[N]=0;
	sort(a,a+N+1); // intentionally not sort(a, a+N)
	int pos=(int)(lower_bound(a,a+1+N,0)-a),ans=0;
	for(int i=1;i<=N;++i){
		int x=i%2,o=(i-1)%2;
		for(int j=0;j<=N;++j){
			for(int k=j;k<=N;++k){
				l[x][j][k]=r[x][j][k]=mx;
				if(j>0){
					l[x][j][k]=min(l[x][j][k],l[o][j-1][k]+i*(a[j]-a[j-1]));
					r[x][j][k]=min(r[x][j][k],l[o][j-1][k]+i*(a[k]-a[j-1]));
				}
				if(k<N){
					l[x][j][k]=min(l[x][j][k],r[o][j][k+1]+i*(a[k+1]-a[j]));
					r[x][j][k]=min(r[x][j][k],r[o][j][k+1]+i*(a[k+1]-a[k]));
				}
			}
		}
		ans=max(ans,i*M-l[x][pos][pos]);
	}
	cout<<ans<<'\n';
	return 0;
}