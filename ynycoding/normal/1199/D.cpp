#include <cstdio>
#include <algorithm>
#define MAXN 200005
int n, q, a[MAXN], check[MAXN], opt[MAXN], x[MAXN], y[MAXN], cur;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	scanf("%d", &q);
	for(int i=1; i<=q; ++i)
	{
		scanf("%d", opt+i);
		if(opt[i]==1) scanf("%d%d", x+i, y+i);
		else scanf("%d", x+i);
	}
	for(int i=q; i; --i)
	{
		if(opt[i]==2) cur=std::max(cur, x[i]);
		else if(!check[x[i]]) a[x[i]]=std::max(y[i], cur), check[x[i]]=1;
	}
	for(int i=1; i<=n; ++i) printf("%d ", (!check[i])?std::max(a[i], cur):a[i]);
	return 0;
}