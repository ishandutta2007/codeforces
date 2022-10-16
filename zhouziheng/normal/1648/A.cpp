#include<cstdio>

using namespace std;

int c[200000];
#define ID(i,j)((((i)-1)*m)+(j))

long long cnt[200000],tot[2000000];

int main()
{
	int n=0,m=0;scanf("%d%d",&n,&m);for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&c[ID(i,j)]),tot[c[ID(i,j)]]++;
	//for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)printf("%d\n",ID(i,j));
	long long ans=0,t=0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int u=c[ID(i,j)];t-=cnt[u]*(tot[u]-cnt[u]);cnt[u]++;t+=cnt[u]*(tot[u]-cnt[u]);
		}
		ans+=t;
	}
	t=0;for(int i=1;i<=100000;i++)cnt[i]=0;
	for(int j=1;j<m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			int u=c[ID(i,j)];t-=cnt[u]*(tot[u]-cnt[u]);cnt[u]++;t+=cnt[u]*(tot[u]-cnt[u]);
		}
		ans+=t;
	}
	printf("%lld",ans);
}