/*
Algorithm practice
Index map
Iteration 1
7/5/2018
*/
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
	map<string,int>m;
	while(true){
		string a;if(!(cin>>a))break;
		int x;
		if(m.find(a)==m.end()){
			x=m.size();
			m[a]=x;
		}else{
			x=m[a];
		}
		cout<<x<<'\n';
	}
	return 0;
}
