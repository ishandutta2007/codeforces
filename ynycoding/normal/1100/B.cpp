#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 100001
int n, m, cur, a[MAXN];
int main()
{
	scanf("%d %d", &n, &m);
	for(int i=1, x; i<=m; ++i)
	{
		scanf("%d", &x);
		++a[x];
		if(a[x]==1) ++cur;
		if(cur==n)
		{
			putchar('1');
			for(int i=1; i<=n; ++i) --a[i], cur-=a[i]?0:1;
		}
		else putchar('0');
	}
	return 0;
}