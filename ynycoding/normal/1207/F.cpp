#include <cstdio>
int n=500000, m=700, q, a[500005], r[705][705];
int main()
{
	scanf("%d", &q);
	for(int i=1, t, x, y; i<=q; ++i)
	{
		scanf("%d%d%d", &t, &x, &y);
		if(t==1)
		{
			a[x]+=y;
			for(int i=1; i<=m; ++i) r[i][x%i]+=y;
		}
		else
		{
			if(x>m)
			{
				int ans=0;
				for(int i=y; i<=n; i+=x) ans+=a[i];
				printf("%d\n", ans);
			}
			else printf("%d\n", r[x][y]);
		}
	}
	return 0;
}