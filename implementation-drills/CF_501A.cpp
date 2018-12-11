/*
Accepted
*/
#include<iostream>
using namespace std;
int getp(int a,int b){
	return max(3*a/10,a-a/250*b);
}
int main(){
	int a,b,c,d,x,y;cin>>a>>b>>c>>d;
	x=getp(a,c);y=getp(b,d);
	if(x>y)cout<<"Misha";
	else if(x<y)cout<<"Vasya";
	else cout<<"Tie";
	cout<<'\n';
	return 0;
}