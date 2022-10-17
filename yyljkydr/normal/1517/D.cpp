#include<bits/stdc++.h>
using namespace std;

const int N=5e2+1e1+7;

int n,m,k,a[N][N],b[N][N],f[11][N][N];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&b[i][j]);
	if(k&1)
	{
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=m;j++,putchar(' '))
				printf("-1");
		return 0;
	}
	for(int i=1;i<=k/2;i++)
	{
		for(int j=1;j<=n;j++)
			for(int t=1;t<=m;t++)
			{
				f[i][j][t]=1e9;
				if(j-1>=1)
					f[i][j][t]=min(f[i][j][t],f[i-1][j-1][t]+b[j-1][t]);
				if(j+1<=n)
					f[i][j][t]=min(f[i][j][t],f[i-1][j+1][t]+b[j][t]);
				if(t-1>=1)
					f[i][j][t]=min(f[i][j][t],f[i-1][j][t-1]+a[j][t-1]);
				if(t+1<=m)
					f[i][j][t]=min(f[i][j][t],f[i-1][j][t+1]+a[j][t]);
			}
	}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++,putchar(' '))
			printf("%d",f[k/2][i][j]*2);
}