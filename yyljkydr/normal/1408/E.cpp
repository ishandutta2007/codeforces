#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int n,m,a[N],b[N];

long long ans=0;

int cnt;

struct E{
	int u,v,w;
}e[N];

int fa[N];

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

bool cmp(E a,E b)
{
	return a.w>b.w;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n+m;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int x;
			scanf("%d",&x);
			e[++cnt]=E{i,x+n,b[x]+a[i]};
			ans+=b[x]+a[i];
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv)
			continue;
		fa[fu]=fv;
		ans-=e[i].w;
	}
	printf("%lld\n",ans);
}