#include<cstdio>
#include<cstring>
using namespace std;
int f[510][510],g[510][510],a[510][510];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)f[i][i]=1,g[i][i]=1;
	for(int i=1;i<n;i++)f[i][i+1]=a[i][i+1],g[i][i+1]=1;
	for(int j=1;j<=n;j++)
	{
		for(int i=j-2;i>=1;i--)
		{
			for(int k=i+1;k<=j;k++)
			{
				g[i][j]=(g[i][j]+1ll*f[i][k-1]*f[k][j])%1000000007;
				if(a[i][k])f[i][j]=(f[i][j]+1ll*g[i][k]*f[k][j])%1000000007;
			}
		}
	}
	printf("%d\n",f[1][n]);
	return 0;
}