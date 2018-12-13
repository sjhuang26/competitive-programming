/*
(failed 30/100; can't debug)

Main ideas:
  * setup of sets can be considered as filling in numbers left-to-right where a(i) = anything in the interval [1, max_in_interval(0, i) + 1].
  * DP, where d[i][j] represents how many possibilities there are if the
    ith position and onwards has to be filled and the max digit is j+1
  * Answer is incrementally built digit by digit
  * DP is iterated from highest to lowest i.
*/
#include<iostream>
using namespace std;
int a[10000],N,x[10000];
typedef long long ll;
ll d[2][10001];//given at nth position (implicit, reverse) and cutoff index (starts at 0): # of possibilities?
const int md=1e6+7,ans=0;
int main(){
  cin>>N;
  for(int i=0;i<N;++i)cin>>a[i];
  int u=0,ans=0;
  for(int i=0;i<N;++i){
    x[i]=u=max(u,a[i]);
  }
  for(int i=0;i<=N;++i){
    d[N%2][i]=1;
  }
  for(int i=N-1;i>=0;--i){
    for(int j=0;j<=i;++j){
      d[i%2][j]=(d[(i+1)%2][j+1]+d[(i+1)%2][j]*j)%md;
    }
    if(i==N-1){
      ans+=(d[i%2][a[i]-1]);
    }else{
      ans+=(d[(i+1)%2][x[i]-1]*(a[i]-1));
    }
    ans%=md;
    //cout<<ans<<endl;
  }
  cout<<ans<<'\n';
  return 0;
}