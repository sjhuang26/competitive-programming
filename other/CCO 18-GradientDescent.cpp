/*
Author: Suhao Jeffrey Huang
Idea:
	* In a 2D array, find the point with the lowest "score"
		using a limited amount of queries
	* Binary search: keep track of a bounding rectangle for the lowest-score
		point, and then query three points near the midpoint of the rectangle
		to reduce its size
*/
#include<iostream>
#include<cmath>
using namespace std;
// This problem is interactive.
int R,C,K,a,b,c,d;
long long r=1e18;
int main(){
	cin>>R>>C>>K;
	// a, b, c, d represent the bounds of the rectangle the lowest-score point
	// could be in
	a=c=1;
	b=R+1;
	d=C+1;
	while(1){
		//cout<<'-'<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<endl;
		int w=b-a,h=d-c;
		if(w==1&&h==1){
			cout<<"? "<<a<<' '<<c<<endl;
			cin>>r;
			cout<<"! "<<r<<endl;
			return 0;
		}
		int mx=(a+b-1)/2,my=(c+d-1)/2; // find the midpoint of the bounding rectangle
		long long qa,qb=1e18,qc=1e18;
		cout<<"? "<<mx<<' '<<my<<endl;
		cin>>qa;
		if(w>1){
			cout<<"? "<<mx+1<<' '<<my<<endl;
			cin>>qb;
			if(qa>qb)a=mx+1;
			else b=mx+1;
		}
		if(h>1){
			cout<<"? "<<mx<<' '<<my+1<<endl;
			cin>>qc;
			if(qa>qc)c=my+1;
			else d=my+1;
		}
		//r=min(r,min(min(qa,qb),qc));
	}
	return 0;
}