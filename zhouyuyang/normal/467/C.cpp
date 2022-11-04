#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define N 5005
#define ll long long
using namespace std;
ll a[N],f[2][N],n,m,k,x,c;
inline ll read(){
	ll k=0;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) k=k*10+ch-48;
	return k;
}
int main(){
	n=read();
	k=read();
	m=read();
	for (int i=1;i<=n;i++){
		x=read();
		a[i]=a[i-1]+x;
	}
	c=0;
	for (int i=1;i<=m;i++){
		c=1-c;
		memset(f[c],0,sizeof(f[c]));
		for (int j=k;j<=n;j++)
			f[c][j]=f[1-c][j-k]+a[j]-a[j-k];
		for (int j=1;j<=n;j++)
			f[c][j]=max(f[c][j],f[c][j-1]);
	}
	printf("%I64d",f[c][n]);
}