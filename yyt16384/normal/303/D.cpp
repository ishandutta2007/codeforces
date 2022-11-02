#include <cstdio>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXD=25;
int n,x,noans;
int d[MAXD];
int dn;
void init()
{
	scanf("%d%d",&n,&x);
	++n;
	int m=n;
	for (int i=2;i*i<=m;++i)
		if (m%i==0)
		{
			noans=1;
			return;
		}
	m=n-1;
	for (int i=2;i*i<=m;++i)
		if (m%i==0)
		{
			d[dn++]=i;
			while (m%i==0) m/=i;
		}
	if (m>1) d[dn++]=m;
}
int powermod(int x,int y,int z)
{
	int s=1;
	while (y)
	{
		if (y&1) s=(long long)s*x%z;
		x=(long long)x*x%z;
		y>>=1;
	}
	return s;
}
void solve()
{
	if (noans)
	{
		printf("-1\n");
		return;
	}
	if (n==2)
	{
		if (x==2) printf("-1\n");
		else printf("%d\n",x-1);
		return;
	}
	for (int i=x-1;i>1;--i)
		if (i%n)
		{
			int fl=1;
			for (int j=0;j<dn;++j)
				if (powermod(i,(n-1)/d[j],n)==1)
				{
					fl=0;break;
				}
			if (fl)
			{
				printf("%d\n",i);
				return;
			}
		}
	printf("-1\n");
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("5485.in","r",stdin);
	freopen("5485.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}