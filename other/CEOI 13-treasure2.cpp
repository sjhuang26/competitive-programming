/*
Author: Suhao Jeffrey Huang
Idea:
	* In a 2D grid, query a series of overlapping rectangles and
		subtract their areas to find the values of the cells
*/
#include "treasure.h"
#include<iostream>
using namespace std;
// This problem is interactive.
int d[101][101]={};
void findTreasure(int n){
	int k=n/2;
	for(int i=n;i>0;--i)for(int j=n;j>0;--j){
		if(i>k&&j>k)d[i][j]=countTreasure(1,1,i,j);
		if(i<=k&&j>k)d[i][j]=d[n][j]-countTreasure(i+1,1,n,j);
		if(i<=k&&j<=k)d[i][j]=d[n][j]+d[i][n]-d[n][n]+countTreasure(i+1,j+1,n,n);
		if(i>k&&j<=k)d[i][j]=d[i][n]-countTreasure(1,j+1,i,n);
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(d[i][j]-d[i-1][j]-d[i][j-1]+d[i-1][j-1])Report(i,j);
}
