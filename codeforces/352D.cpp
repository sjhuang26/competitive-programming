/*
Codeforces
352D
*/
#include<iostream>
#include<stack>
using namespace std;
int N,n=0,a[100000];
stack<int>s;
int main(){
	cin>>N;
	for(int i=0;i<N;++i)cin>>a[i];
	for(int i=0;i<N;++i)for(int j=i+1;j<N;++j)n+=(a[i]>a[j]);
	//cout<<n<<'\n';
	cout<<(n%2?1+(n-1)*2:2*n)<<'\n';
	return 0;
}
