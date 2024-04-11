#include <cstdio>
#include <algorithm>
#define ll long long
#define MAXN 100005
int n, m, a[MAXN], c[MAXN], id[MAXN], idx;
bool cmp(int x, int y) { return c[x]==c[y]?x<y:c[x]<c[y]; }
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=n; ++i) scanf("%d", c+i), id[i]=i;
	std::sort(id+1, id+n+1, cmp), idx=1;
	for(int i=1, x, y; i<=m; ++i)
	{
		scanf("%d%d", &x, &y);
		if(a[x]>=y) a[x]-=y, printf("%lld\n", (ll)y*c[x]);
		else
		{
			ll ans=0;
			y-=a[x];
			ans=(ll)a[x]*c[x];
			a[x]=0;
			while(y&&idx<=n)
			{
				if(!a[id[idx]]) ++idx;
				else if(a[id[idx]]<y) y-=a[id[idx]], ans+=(ll)c[id[idx]]*a[id[idx]], a[id[idx]]=0, ++idx;
				else a[id[idx]]-=y, ans+=(ll)y*c[id[idx]], y=0;
			}
			if(y)
			{
				for(; i<=m; ++i) puts("0");
				return 0;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}