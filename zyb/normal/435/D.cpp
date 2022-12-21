#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N=400;
int le[N+3][N+3],ri[N+3][N+3],up[N+3][N+3],down[N+3][N+3],xl1[N+3][N+3],xr1[N+3][N+3],xl2[N+3][N+3],xr2[N+3][N+3];
int a[N+3][N+3],n,m,ans;char s[N+3];

int main()
{
scanf("%d%d",&n,&m);
for (int i=1;i<=n;i++)
  {
  scanf("%s",s+1);
  for (int j=1;j<=m;j++) a[i][j]=s[j]=='1';
  }
for (int i=1;i<=n;i++)
  {
  for (int j=1;j<=m;j++)
    if (!a[i][j]) le[i][j]=le[i][j-1]+1;
  for (int j=m;j>=1;j--)
    if (!a[i][j]) ri[i][j]=ri[i][j+1]+1;
  for (int j=1;j<=m;j++)
    if (!a[i][j])
	  {
	  up[i][j]=up[i-1][j]+1;
	  xl1[i][j]=xl1[i-1][j-1]+1;
	  xr1[i][j]=xr1[i-1][j+1]+1;
	  }
  }
for (int i=n;i>=1;i--)
  {
  for (int j=1;j<=m;j++)
    if (!a[i][j])
	  {
	  down[i][j]=down[i+1][j]+1;
	  xl2[i][j]=xl2[i+1][j-1]+1;
	  xr2[i][j]=xr2[i+1][j+1]+1;
	  }
  }
for (int i=1;i<=n;i++)
  for (int j=1;j<=m;j++)
    if (!a[i][j])
	  for (int k=j+1;k<=m;k++)
	    {
		int dd=k-j+1;
		if (ri[i][j]>=dd&&up[i][j]>=dd&&xl1[i][k]>=dd) ans++;
		if (ri[i][j]>=dd&&up[i][k]>=dd&&xr1[i][j]>=dd) ans++;
		if (ri[i][j]>=dd&&down[i][j]>=dd&&xl2[i][k]>=dd) ans++;
		if (ri[i][j]>=dd&&down[i][k]>=dd&&xr2[i][j]>=dd) ans++;
		if (up[i][j]>=dd&&down[i][j]>=dd&&xl1[i][k]>=dd&&xl2[i][k]>=dd) ans++;
		if (up[i][k]>=dd&&down[i][k]>=dd&&xr1[i][j]>=dd&&xr2[i][j]>=dd) ans++;
		if (ri[i][j]>=dd&&xr1[i][j]>=dd&&ri[i][k]>=dd&&xl1[i][k+dd-1]>=dd) ans++;
		if (ri[i][j]>=dd&&xr2[i][j]>=dd&&ri[i][k]>=dd&&xl2[i][k+dd-1]>=dd) ans++;
		}
printf("%d",ans);
}