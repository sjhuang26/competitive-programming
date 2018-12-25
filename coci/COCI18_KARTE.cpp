/*
COCI18_KARTE

Key ideas:
- Any arrangement can be re-arranged so that all the TRUE cards are at the top of the deck.
- Therefore, we simply test for the potential existence of a TTTTTTT.....FFFFFF arrangement.
- This can be done by sorting the given numbers and a greedy-algorithm approach.
*/
#include<iostream>
#include<algorithm>
int N,K,a[500000],ans[500000];
using namespace std;
int main(){
	cin>>N>>K;
	for(int i=0;i<N;++i)cin>>a[i];
	sort(a,a+N);
	int b=0;
	while(b!=N&&a[b]<=K)++b;
	if(N-b>K){
		cout<<-1<<'\n';
	}else{
		int j=N-1,k=K;
		for(int i=N-K;i<N;++i){
			if(a[j]<k){
				cout<<-1<<'\n';return 0;
			}else{
				ans[i]=a[j];
				--j;--k;
			}
		}
		for(int i=0;i<N-K;++i){
			ans[i]=a[j];
			--j;
		}
		for(int i=0;i<N;++i){
			cout<<ans[i];if(i!=N-1)cout<<' ';
		}
		cout<<'\n';
	}
	return 0;
}