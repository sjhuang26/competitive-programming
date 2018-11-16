/*
Codeforces
344D
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
	string a;cin>>a;
	int r=0;
	for(char i:a){
		bool x=i=='+';
		if(r%2){
			if(x)--r;
			else ++r;
		}else{
			if(x)++r;
			else --r;
		}
	}
	cout<<(r==0?"Yes":"No")<<'\n';
	return 0;
}
