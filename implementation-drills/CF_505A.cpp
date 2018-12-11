/*
Accepted
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;cin>>s;int n=s.size();
	for(int i=0;i<n+1;++i){
		bool w=1;
		for(int j=0;j<n+1;++j){
			int x=n-j;
			if(!(j==i||x==i)){
				char a=(j<i?s[j]:s[j-1]),b=(x<i?s[x]:s[x-1]);
				if(a!=b){
					w=0;break;
				}
			}
		}
		if(w){
			string res="";
			for(int j=0;j<i;++j){
				res+=s[j];
			}//abcdef abcdxef
			int k=n-i;
			if(k==i)res+="a";
			else if(k>i)res+=s[k-1];
			else res+=s[k];
			for(int j=i;j<n;++j){
				res+=s[j];
			}
			cout<<res<<'\n';
			return 0;
		}
	}
	cout<<"NA\n";return 0;
}