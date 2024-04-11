#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int n,k,m;

int u[N],v[N],w[N],a[N],b[N];

int f[N][N];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		scanf("%d",&w[i]);
		f[u[i]][v[i]]=min(f[u[i]][v[i]],w[i]);
		f[v[i]][u[i]]=min(f[v[i]][u[i]],w[i]);
	}
	for(int i=1;i<=k;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int s=0,ans=1e9;
	for(int i=1;i<=k;i++)
		s+=f[a[i]][b[i]];
	for(int i=1;i<=m;i++)
	{
		int sw=0;
		for(int j=1;j<=k;j++)
		{
			sw+=min({f[a[j]][u[i]]+f[b[j]][v[i]],f[b[j]][u[i]]+f[a[j]][v[i]],f[a[j]][b[j]]});
		}
		ans=min(ans,sw);
	}
	printf("%d\n",ans);
}