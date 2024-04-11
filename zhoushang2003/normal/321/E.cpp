#include<bits/stdc++.h>
using namespace std;
const int N=4001,I=1e9;
int n,m,a[N][N],s[N][N],f[N],g[N],t;
inline int G()
{
	char c;
	while((c=getchar())<'0'||c>'9');
	return c-'0';
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=G();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	g[n+1]=n;
	for(int k=2;k<=m;k++)
		for(int i=n;i;i--)
		{
			f[i]=-I;
			for(int j=g[i];j<=g[i+1]&&j<i;j++)
			{
				t=f[j]-s[j][j]+s[j][i];
				if(t>f[i])
					f[i]=t,g[i]=j;
			}
		}
	cout<<s[n][n]/2-f[n];
	return 0;
}