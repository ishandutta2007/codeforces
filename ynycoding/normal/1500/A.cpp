#include <cstdio>
#include <algorithm>
const int N=2500005;
int n, a[N], cnt[N], id[N], x, y, c, d, lim=4000, mx;
int idx[N<<1], idy[N<<1];
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), mx=std::max(mx, a[i]), id[a[i]]=i, ++cnt[a[i]];
	for(int i=1; i<=mx; ++i) if(cnt[i]>=4)
	{
		int cnt=0;
		puts("YES");
		for(int j=1; j<=n; ++j) if(a[j]==i)
		{
			printf("%d ", j);
			++cnt;
			if(cnt==4) return 0;
		}
	}
	for(int i=1; i<=mx; ++i) if(cnt[i]>=2)
	{
		x?y=i:x=i;
	}
	if(x&&y)
	{
//		printf("xy %d %d\n", x, y);
		for(int i=1; i<=n; ++i) if(i!=id[x]&&i!=id[y]&&(a[i]==x||a[i]==y))
		{
			if(a[i]==x) c=i;
			else d=i;
		}
		printf("YES\n%d %d %d %d\n", id[x], id[y], c, d);
		return 0;
	}
	if(n>=lim)
	{
		puts("YES");
		for(int i=1, pr=0; i<=mx; ++i) if(id[i])
		{
			if(pr)
			{
				if(idx[i-pr])
				{
					printf("%d %d %d %d\n", id[idx[i-pr]], id[i], id[idx[i-pr]+i-pr], id[pr]);
					return 0;
				}
				idx[i-pr]=pr;
			}
			pr=i;
		}
	}
	for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) if(idx[a[i]+a[j]])
	{
		int x=idx[a[i]+a[j]], y=idy[a[i]+a[j]];
		if(x!=i&&x!=j&&y!=i&&y!=j)
		{
			puts("YES");
			printf("%d %d %d %d\n", x, y, i, j);
			return 0;
		}
	}
	else idx[a[i]+a[j]]=i, idy[a[i]+a[j]]=j;
	puts("NO");
	return 0;
}