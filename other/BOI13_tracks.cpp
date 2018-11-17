#include<iostream>
#include<queue>
#include<string>
using namespace std;
typedef pair<int,int>ii;
queue<ii>q[2];
int R,C,K=0,res=0;
bool s;
string d[4000];
const string fr="FR";
int main(){
	cin>>R>>C;
	q[0]=queue<ii>();
	q[1]=queue<ii>();
	for(int i=0;i<R;++i){
		cin>>ws;
		cin>>d[i];
		for(int j=0;j<C;++j)if(d[i][j]=='.')++K;
	}
	s=d[0][0]==fr[1];
	d[0][0]='.';
	q[s].push({0,0});
	while(K<R*C){
		//cout<<"---"<<K<<endl;
		//cout<<q[0].size()<<' '<<q[1].size()<<endl;
		++res;
		q[!s]=queue<ii>();
		while(!q[s].empty()){
			++K;
			//cout<<"IT"<<endl;
			ii rw=q[s].front();
			int x=rw.first,y=rw.second;
			//cout<<q[s].size()<<' '<<x<<' '<<y<<endl;
			q[s].pop();
			if(0<x&&d[x-1][y]!='.'){
				q[d[x-1][y]==fr[1]].push({x-1,y});
				d[x-1][y]='.';
			}
			if(x<R-1&&d[x+1][y]!='.'){
				q[d[x+1][y]==fr[1]].push({x+1,y});
				d[x+1][y]='.';
			}
			if(0<y&&d[x][y-1]!='.'){
				q[d[x][y-1]==fr[1]].push({x,y-1});
				d[x][y-1]='.';
			}
			if(y<C-1&&d[x][y+1]!='.'){
				q[d[x][y+1]==fr[1]].push({x,y+1});
				d[x][y+1]='.';
			}
		}
		s=!s;
	}
	cout<<res<<'\n';
	return 0;
}