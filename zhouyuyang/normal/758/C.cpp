#include<cstring>
#include<cmath>   
#include<cstdio>  
#include<iostream>  
#include<cstdlib>   
#include<algorithm>
#define ll long long
using namespace std;
ll f[105][105],n,m,k,x,y,mi,mo,ppp,qqq;
int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&k,&x,&y);
	if (n==1) mo=m; else mo=(ll)2*(n-1)*m;
	mi=k/mo;
	k%=mo;
	if (n==1)
		for (int i=1;i<=m&&k>0;i++,k--) f[1][i]=1;
	else{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (k>0) f[i][j]+=1,k--;
		for (int i=n-1;i>1;i--)
			for (int j=1;j<=m;j++)
				if (k>0) f[i][j]+=1,k--;
	}
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=m;j++) f[i][j]+=mi;
	for (int i=n-1;i>1;i--) 
		for (int j=1;j<=m;j++) f[i][j]+=mi;
	ppp=8000000000000000000;
	qqq=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (f[i][j]<ppp) ppp=f[i][j];
			if (f[i][j]>qqq) qqq=f[i][j]; 
		}
	printf("%I64d %I64d %I64d",qqq,ppp,f[x][y]);
}