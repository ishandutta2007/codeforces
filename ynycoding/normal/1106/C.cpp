#include <cstdio>
#include <algorithm>
#define ll long long
#define MAXN 300005
int n, a[MAXN];
ll ans;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	std::sort(a+1, a+n+1);
	for(int i=1; i<=(n>>1); ++i) ans+=(ll)(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
	printf("%lld", ans);
	return 0;
}