/*
Codeforces
617D
*/
#include<iostream>
using namespace std;
int a,b,c,d,e,f;
bool dop(int a,int b,int c,int d,int e,int f){
	if(b==d&&!(a<e&&e<c||c<e&&e<a))return 1;
	if(a==c&&!(b<f&&f<d||d<f&&f<b))return 1;
	//cout<<a<<b<<c<<d<<e<<f<<endl;
	return 0;
}
int calc(){
	if(a==c&&c==e||b==d&&d==f)return 1;
	int t;
	if(dop(a,b,c,d,e,f))return 2;
	if(dop(a,b,e,f,c,d))return 2;
	if(dop(c,d,e,f,a,b))return 2;
	return 3;
}
int main(){
	cin>>a>>b>>c>>d>>e>>f;
	cout<<calc()<<'\n';
	return 0;
}
