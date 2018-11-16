/*
UVa
196
*/
#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<tuple>
using namespace std;
int main(){
	int T;cin>>T;
	for(int t=0;t<T;++t){
		int C,R;cin>>C>>R;
		// A vector of vectors of vectors of pairs of int/int
		// initialized with R items of vectors of vectors of
		// pairs of int/int initialized with C items.
		// (The contents of the cells.)
		vector<vector<vector<pair<int,int>>>>s(R,vector<vector<pair<int,int>>>(C));
		vector<vector<int>>v(R,vector<int>(C));
		vector<vector<bool>>f(R,vector<bool>(C));//NOT calculated yet
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				string x;cin>>x;
				int X=x.size();
				if(x[0]=='='){
					f[i][j]=1;
					int cv=0,rv=0,ia=i;
					for(int i=1;i<X;++i){
						//cout<<cv<<rv<<endl;
						char c=x[i];
						if('A'<=c&&c<='Z')cv*=26,cv+=c-'A'+1;
						else if('0'<=c&&c<='9')rv*=10,rv+=c-'0';
						else{
							s[ia][j].push_back({rv-1,cv-1});
							cv=0;
							rv=0;
						}
					}
					//cout<<'1'<<endl;
					s[i][j].push_back({rv-1,cv-1});
					cv=0;
					rv=0;
				}else{
					f[i][j]=0;
					v[i][j]=stoi(x);
				}
			}
		}
		stack<pair<int,int>>q;
		for(int i=0;i<R;++i)for(int j=0;j<C;++j)q.push({i,j});
		while(!q.empty()){
			int r,c;tie(r,c)=q.top();
			//cout<<r<<' '<<c<<endl;
			if(f[r][c]){
				int x=0;
				f[r][c]=0;
				for(auto i:s[r][c]){
					if(f[i.first][i.second]){
						f[r][c]=1;
						q.push({i.first,i.second});
					}else{
						x+=v[i.first][i.second];
					}
				}
				if(!f[r][c])v[r][c]=x;
			}
			if(!f[r][c]){//this placement is intentional
				q.pop();
			}
		}
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				cout<<v[i][j];
				if(j!=C-1)cout<<' ';
			}
			cout<<'\n';
		}
	}
	return 0;
}
