#include <cstdio>
#include <algorithm>
#define ld long double
#define ll long long
#define MAXN 100005
ll n, k, m, a[MAXN];
ll tot;
ld mx;
int main()
{
	scanf("%lld%lld%lld", &n, &k, &m);
	for(int i=1; i<=n; ++i) scanf("%lld", a+i), tot+=a[i];
	std::sort(a+1, a+n+1);
	for(int i=1; i<=n&&i<=m+1; tot-=a[i], ++i)
		mx=std::max(mx, (ld)(tot+std::min((n-i+1)*k, m-i+1))/(n-i+1));
	printf("%.12Lf", mx);
	return 0;
}