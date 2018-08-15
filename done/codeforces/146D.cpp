/*
Codeforces
146D
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
	int a,b,c,d,ta,tb;string r;cin>>a>>b>>c>>d;//4 7 47 74
	if(c==d){
		ta=1+d;
		tb=c;
		if(a>=ta&&b>=tb){
			for(int i=0;i<=a-ta;++i)r+="4";
			for(int i=0;i<tb;++i){
				if(i==tb-1)for(int i=0;i<=b-tb;++i)r+="7";
				else r+="7";
				r+="4";
			}
			cout<<r<<'\n';
			return 0;
		}
	}
	if(c==d+1){
		ta=1+d;
		tb=c;
		if(a>=ta&&b>=tb){
			for(int i=0;i<ta;++i){
				if(i==0)for(int i=0;i<=a-ta;++i)r+="4";
				else r+="4";
				if(i==tb-1)for(int i=0;i<=b-tb;++i)r+="7";
				else r+="7";
			}
			//for(int i=0;i<=a-ta;++i)r+="4";
			//for(int i=0;i<tb-1;++i)r+="74";
			//for(int i=0;i<=b-tb;++i)r+="7";
			cout<<r<<'\n';
			return 0;
		}
	}
	if(c+1==d){
		ta=d;
		tb=1+c;
		if(a>=ta&&b>=tb){
			for(int i=0;i<tb;++i){
				if(i==tb-1)for(int i=0;i<=b-tb;++i)r+="7";
				else r+="7";
				if(i==0)for(int i=0;i<=a-ta;++i)r+="4";
				else r+="4";
			}
			cout<<r<<'\n';
			return 0;
		}
	}
	if(c==d){
		ta=d;
		tb=1+c;
		if(a>=ta&&b>=tb){
			r+="7";
			for(int i=0;i<ta;++i){
				if(i==0)for(int i=0;i<=a-ta;++i)r+="4";
				else r+="4";
				if(i==ta-1)for(int i=0;i<=b-tb;++i)r+="7";
				else r+="7";
			}
			cout<<r<<'\n';
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}
