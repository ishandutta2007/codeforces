#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define ll long long
#define N 1005
using namespace std;
ll n,m,ans,a[N][N],b[N][N],c[N][N],d[N][N],e[N][N];
inline ll read(){
	ll k=0;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) k=k*10+ch-48;
	return k;
}
int main(){
	n=read();
	m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) a[i][j]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) b[i][j]=max(b[i-1][j],b[i][j-1])+a[i][j];
	for (int i=n;i>=1;i--)
		for (int j=1;j<=m;j++) c[i][j]=max(c[i+1][j],c[i][j-1])+a[i][j];
	for (int i=1;i<=n;i++)
		for (int j=m;j>=1;j--) d[i][j]=max(d[i-1][j],d[i][j+1])+a[i][j];
	for (int i=n;i>=1;i--)
		for (int j=m;j>=1;j--) e[i][j]=max(e[i+1][j],e[i][j+1])+a[i][j];
	for (int i=2;i<n;i++)
		for (int j=2;j<m;j++)
			ans=max(ans,max(b[i][j-1]+e[i][j+1]+d[i-1][j]+c[i+1][j],c[i][j-1]+d[i][j+1]+b[i-1][j]+e[i+1][j]));
	printf("%I64d",ans);
}