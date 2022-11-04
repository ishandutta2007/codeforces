#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define N 5005
#define ll long long
using namespace std;
ll a[3][3],f[3][3][50];
int n,v[3][3][50];
ll dfs(int l,int r,int n){
	int x=3-l-r;
	if (n==1) return min(a[l][r],a[l][x]+a[x][r]);
	if (v[l][r][n]) return f[l][r][n];
	v[l][r][n]=1;
	return f[l][r][n]=min(dfs(l,x,n-1)+dfs(x,r,n-1)+a[l][r],2*dfs(l,r,n-1)+dfs(r,l,n-1)+a[l][x]+a[x][r]);
}
int main(){
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++) scanf("%I64d",&a[i][j]);
	scanf("%d",&n);
	printf("%I64d",dfs(0,2,n));
}