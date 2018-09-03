/*
SPOJ
HISTOGRA
*/
#include<iostream>
#include<stack>
using namespace std;
int a[100000],pl[100000],pr[100000];
int main(){
	while(1){
		int N;cin>>N;
		if(N==0)break;
		for(int i=0;i<N;++i)cin>>a[i];
		stack<int>s;
		for(int i=0;i<N;++i){
			while(!s.empty()&&a[s.top()]>=a[i])s.pop();
			if(s.empty())pl[i]=-1;
			else pl[i]=s.top();
			s.push(i);
		}
		while(!s.empty())s.pop();
		for(int i=N-1;i>=0;--i){
			while(!s.empty()&&a[s.top()]>=a[i])s.pop();
			if(s.empty())pr[i]=N;
			else pr[i]=s.top();
			s.push(i);
		}
		long long r=-1;
		for(int i=0;i<N;++i){
			//cout<<pl[i]<<' '<<pr[i]<<'\n';
			r=max(r,(long long)a[i]*(pr[i]-pl[i]-1));
		}
		cout<<r<<'\n';
	}
	return 0;
}
