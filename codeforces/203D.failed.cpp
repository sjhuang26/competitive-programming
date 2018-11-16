/*
Codeforces
203D
*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double a,b,m,x,y,z,ra,rb;
int md(int a,int b){
	return ((a%b)+b)%b;
}
double md(double a,double b){
	return fmod((fmod(a,b)+b),b);
}
int main(){
	cin>>a>>b>>m>>x>>y>>z;
	ra=-m/y*x+a/2;
	rb=-m/y*z;
	if(md((int)(ra/a),2)==1)ra=a-md(ra,a);else ra=md(ra,a);
	if(md((int)(rb/b),2)==1)rb=b-md(rb,b);else rb=md(rb,b);
	cout<<fixed<<setprecision(10)<<ra<<' '<<rb<<'\n';
	return 0;
}
