/*
Incorrect solution; cannot debug.

Author: Suhao Jeffrey Huang
Idea:
    * Park can be modeled as a graph where nodes = "trees" (plants)
    and an edge between two trees means that the visitor can't pass between them.
    * Disjoint-set data structure is used.
    * Distances between trees are precomputed.
    * A visitor that is small can reach any of the corners. A visitor too big can't reach anything. Binary search is used
    to find the maximum possible visitor radius that works. This is done for each pair of corners. 
*/
#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int p[2004],h[2004],x[100000],y[100000],r[100000],N,M,W,H,cut[4][4];
double dist[2000][2000];
int getp(int n){
  return p[n]==n?n:p[n]=getp(p[n]);
}
void unionset(int a,int b){
  a=getp(a);b=getp(b);
  if(a!=b){
    if(h[a]<h[b])p[a]=b;
    else if(h[a]>h[b])p[b]=a;
    else p[a]=b,++h[b];
  }
}
bool sameset(int a,int b){
  return getp(a)==getp(b);
}
bool works(int n,int u,int v){
  //cout<<n<<' '<<u<<' '<<v<<endl;
  for(int i=0;i<N+4;++i)h[i]=1,p[i]=i;
  for(int i=0;i<N;++i){
    for(int j=i+1;j<N;++j){
      if(dist[i][j]+0.000001<r[i]+r[j]+2*n)unionset(i,j);
    }
    if(H-y[i]<2*n)unionset(i,N+2);
    if(y[i]<2*n)unionset(i,N);
    if(W-x[i]<2*n)unionset(i,N+1);
    if(x[i]<2*n)unionset(i,N+3);
  }
  if(sameset(N+0,N+3)&&(u==0||v==0))return 0;
  if(sameset(N+1,N+0)&&(u==1||v==1))return 0;
  if(sameset(N+2,N+1)&&(u==2||v==2))return 0;
  if(sameset(N+3,N+2)&&(u==3||v==3))return 0;
  if(sameset(N+0,N+2)&&!((u==0&&v==3)||(u==1&&v==2)))return 0;
  if(sameset(N+1,N+3)&&!((u==0&&v==1)||(u==2&&v==3)))return 0;
  return 1;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>N>>M>>W>>H;
  for(int i=0;i<N;++i)cin>>x[i]>>y[i]>>r[i];
  // precompute distances
  for(int i=0;i<N;++i)for(int j=i+1;j<N;++j){
    dist[i][j]=sqrt((double)(x[i]-x[j]+y[i]-y[j])*(x[i]-x[j]-y[i]+y[j]));
  }
  for(int i=0;i<4;++i)for(int j=0;j<4;++j)if(i<j){
    int maxworks=-1,lo=0,hi=1e9;
    while(lo<=hi){
      int md=(lo+hi)/2;
      if(works(md,i,j)){
        maxworks=md;
        lo=md+1;
      }else{
        hi=md-1;
      }
    }
    cut[i][j]=maxworks;
  }else if(i>j)cut[i][j]=cut[j][i];
  else cut[i][j]=1e9;
  for(int i=0;i<M;++i){
    int v,e;cin>>v>>e;--e;
    string res="";
    for(int j=0;j<4;++j)if(cut[e][j]>=v){
      res+='1'+j;
    }
    cout<<res<<"\n";
  }
  return 0;
}
