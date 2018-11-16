/*
SPOJ
QUEEN
*/
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
typedef pair<int,int>ii;
string a[1000];
int d[1000][1000];
int main(){
	int T;cin>>T;
	for(int t=0;t<T;++t){
		int R,C,sr,sc;cin>>R>>C;
		cin>>ws;
		for(int i=0;i<R;++i){
			getline(cin,a[i]);
			for(int j=0;j<C;++j){
				char c=a[i][j];
				if(c=='S')sr=i,sc=j,a[i][j]='.';
			}
		}
		queue<ii>q;
		int D=0,res=-1;
		q.push({sr,sc});
		for(int i=0;i<R;++i)for(int j=0;j<C;++j)d[i][j]=1e9;
		d[sr][sc]=0;
		while(!q.empty()&&res==-1){
			int Q=q.size();
//			cout<<"NEW\n";
			for(int i=0;i<Q;++i){
				auto x=q.front();q.pop();
				int r=x.first,c=x.second;
				char ch=a[r][c];
//				cout<<r<<' '<<c<<'\n';
				for(int i=-1;i<2;++i)for(int j=-1;j<2;++j){
					if(i==0&&j==0)continue;
					int rp=r+i,cp=c+j;
					while(0<=rp&&rp<R&&0<=cp&&cp<C&&a[rp][cp]!='X'&&d[rp][cp]>=D){
						if(a[rp][cp]=='F'){
							res=D+1;
							goto fin;
						}
						if(d[rp][cp]==1e9)d[rp][cp]=D,q.push({rp,cp});
						rp+=i;
						cp+=j;
					}
				}
			}
			++D;
		}
		fin:
		cout<<res<<'\n';
	}
	return 0;
}
