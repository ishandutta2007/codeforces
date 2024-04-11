#include <cstdio>
#include <algorithm>
#define MAXN 100005
int n, m, k, l, r, pre, a[MAXN], ans;
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	if(n==1) return puts("1"), 0;
	--k;
	scanf("%d", &l), pre=l;
	for(int i=1; i<n; ++i) scanf("%d", &r), a[i]=-r+pre+1, pre=r;
	ans=r-l+1;
	std::sort(a+1, a+n);
	for(int i=1; i<=k; ++i) ans+=a[i];
	printf("%d", ans);
	return 0;
}