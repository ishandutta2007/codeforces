#include <cstdio>
#include <algorithm>
#define N 500005
int n, a[N], f[N], cnt[N], c[N], ok[N], l[N], r[N], ans;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=n; i; --i) l[a[i]]=i;
	for(int i=1; i<=n; ++i) ++cnt[a[i]], r[a[i]]=i;
	for(int i=1; i<=n; ++i)
	{
		f[i]=std::max(f[i], f[i-1]);
		if(!ok[a[i]]) ok[a[i]]=1, f[r[a[i]]]=f[i-1]+cnt[a[i]];
		ans=std::max(ans, f[i-1]+cnt[a[i]]-c[a[i]]);
		++c[a[i]];
	}
	printf("%d\n", n-ans);
	return 0;
}